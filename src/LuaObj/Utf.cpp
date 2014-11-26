#include "Utf.h"
#include <stdlib.h>

void EncodeCharUTF8( int nUChar, char* pszUTF8, int& nUTF8Len );
int DecodeCharUTF8( const char*& pszUTF8, const char* pszUTF8End = NULL );
void EncodeCharUTF16( int nUChar, unsigned short* pwszUTF16, int& nUTF16Len );
int DecodeCharUTF16( const unsigned short*& pwszUTF16, const unsigned short* pszUTF16End = NULL );
bool DetectUTF8( const char* pText, int nTextLen, int* pnNonASCII = NULL, bool* bErrorAtEnd = NULL );



bool DetectUTF8( const char* pText, int nTextLen, int* pnNonASCII/*=NULL*/, bool* bErrorAtEnd/*=NULL*/ )
{
	// return true if ASCII or all non-ASCII byte sequences are valid UTF-8 pattern:
	// ASCII   0xxxxxxx
	// 2-byte  110xxxxx 10xxxxxx
	// 3-byte  1110xxxx 10xxxxxx 10xxxxxx
	// 4-byte  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
	// *pnNonASCII is set (if pnNonASCII is not NULL) to the number of non-ASCII UTF-8 sequences
	// or if an invalid UTF-8 sequence is found, to 1 + the valid non-ASCII sequences up to the invalid sequence
	// *bErrorAtEnd is set (if bErrorAtEnd is not NULL) to true if the UTF-8 was cut off at the end in mid valid sequence
	int nUChar;
	if ( pnNonASCII )
		*pnNonASCII = 0;
	const char* pTextEnd = pText + nTextLen;
	while ( *pText && pText != pTextEnd )
	{
		if ( (unsigned char)(*pText) & 0x80 )
		{
			if ( pnNonASCII )
				++(*pnNonASCII);
			nUChar = DecodeCharUTF8( pText, pTextEnd );
			if ( nUChar == -1 )
			{
				if ( bErrorAtEnd )
					*bErrorAtEnd = (pTextEnd == pText)? true:false;
				return false;
			}
		}
		else
			++pText;
	}
	if ( bErrorAtEnd )
		*bErrorAtEnd = false;
	return true;
}

int DecodeCharUTF8( const char*& pszUTF8, const char* pszUTF8End/*=NULL*/ )
{
	// Return Unicode code point and increment pszUTF8 past 1-4 bytes
	// pszUTF8End can be NULL if pszUTF8 is null terminated
	int nUChar = (unsigned char)*pszUTF8;
	++pszUTF8;
	if ( nUChar & 0x80 )
	{
		int nExtraChars;
		if ( ! (nUChar & 0x20) )
		{
			nExtraChars = 1;
			nUChar &= 0x1f;
		}
		else if ( ! (nUChar & 0x10) )
		{
			nExtraChars = 2;
			nUChar &= 0x0f;
		}
		else if ( ! (nUChar & 0x08) )
		{
			nExtraChars = 3;
			nUChar &= 0x07;
		}
		else
			return -1;
		while ( nExtraChars-- )
		{
			if ( pszUTF8 == pszUTF8End || ! (*pszUTF8 & 0x80) )
				return -1;
			nUChar = nUChar<<6;
			nUChar |= *pszUTF8 & 0x3f;
			++pszUTF8;
		}
	}
	return nUChar;
}

void EncodeCharUTF16( int nUChar, unsigned short* pwszUTF16, int& nUTF16Len )
{
	// Write UTF-16 sequence to pwszUTF16 for Unicode code point nUChar and update nUTF16Len
	// Be sure pwszUTF16 has room for up to 2 wide chars
	if ( nUChar & ~0xffff )
	{
		if ( pwszUTF16 )
		{
			// Surrogate pair
			nUChar -= 0x10000;
			pwszUTF16[nUTF16Len++] = (unsigned short)(((nUChar>>10) & 0x3ff) | 0xd800); // W1
			pwszUTF16[nUTF16Len++] = (unsigned short)((nUChar & 0x3ff) | 0xdc00); // W2
		}
		else
			nUTF16Len += 2;
	}
	else
	{
		if ( pwszUTF16 )
			pwszUTF16[nUTF16Len++] = (unsigned short)nUChar;
		else
			++nUTF16Len;
	}
}

int DecodeCharUTF16( const unsigned short*& pwszUTF16, const unsigned short* pszUTF16End/*=NULL*/ )
{
	// Return Unicode code point and increment pwszUTF16 past 1 or 2 (if surrogrates) UTF-16 code points
	// pszUTF16End can be NULL if pszUTF16 is zero terminated
	int nUChar = *pwszUTF16;
	++pwszUTF16;
	if ( (nUChar & ~0x000007ff) == 0xd800 ) // W1
	{
		if ( pwszUTF16 == pszUTF16End || ! (*pwszUTF16) ) // W2
			return -1; // incorrect UTF-16
		nUChar = (((nUChar & 0x3ff) << 10) | (*pwszUTF16 & 0x3ff)) + 0x10000;
		++pwszUTF16;
	}
	return nUChar;
}

void EncodeCharUTF8( int nUChar, char* pszUTF8, int& nUTF8Len )
{
	// Write UTF-8 sequence to pszUTF8 for Unicode code point nUChar and update nUTF8Len
	// Be sure pszUTF8 has room for up to 4 bytes
	if ( ! (nUChar & ~0x0000007f) ) // < 0x80
	{
		if ( pszUTF8 )
			pszUTF8[nUTF8Len++] = (char)nUChar;
		else
			++nUTF8Len;
	}
	else if ( ! (nUChar & ~0x000007ff) ) // < 0x800
	{
		if ( pszUTF8 )
		{
			pszUTF8[nUTF8Len++] = (char)(((nUChar&0x7c0)>>6)|0xc0);
			pszUTF8[nUTF8Len++] = (char)((nUChar&0x3f)|0x80);
		}
		else
			nUTF8Len += 2;
	}
	else if ( ! (nUChar & ~0x0000ffff) ) // < 0x10000
	{
		if ( pszUTF8 )
		{
			pszUTF8[nUTF8Len++] = (char)(((nUChar&0xf000)>>12)|0xe0);
			pszUTF8[nUTF8Len++] = (char)(((nUChar&0xfc0)>>6)|0x80);
			pszUTF8[nUTF8Len++] = (char)((nUChar&0x3f)|0x80);
		}
		else
			nUTF8Len += 3;
	}
	else // < 0x110000
	{
		if ( pszUTF8 )
		{
			pszUTF8[nUTF8Len++] = (char)(((nUChar&0x1c0000)>>18)|0xf0);
			pszUTF8[nUTF8Len++] = (char)(((nUChar&0x3f000)>>12)|0x80);
			pszUTF8[nUTF8Len++] = (char)(((nUChar&0xfc0)>>6)|0x80);
			pszUTF8[nUTF8Len++] = (char)((nUChar&0x3f)|0x80);
		}
		else
			nUTF8Len += 4;
	}
}

int UTF16To8( char* pszUTF8, const unsigned short* pwszUTF16, int nUTF8Count )
{
	// Supports the same arguments as wcstombs
	// the pwszUTF16 source must be a NULL-terminated UTF-16 string
	// if pszUTF8 is NULL, the number of bytes required is returned and nUTF8Count is ignored
	// otherwise pszUTF8 is filled with the result string and NULL-terminated if nUTF8Count allows
	// nUTF8Count is the byte size of pszUTF8 and must be large enough for the NULL if NULL desired
	// and the number of bytes (excluding NULL) is returned
	//
	int nUChar, nUTF8Len = 0;
	while ( *pwszUTF16 )
	{
		// Decode UTF-16
		nUChar = DecodeCharUTF16( pwszUTF16, NULL );
		if ( nUChar == -1 )
			nUChar = '?';

		// Encode UTF-8
		if ( pszUTF8 && nUTF8Len + 4 > nUTF8Count )
		{
			int nUTF8LenSoFar = nUTF8Len;
			EncodeCharUTF8( nUChar, NULL, nUTF8Len );
			if ( nUTF8Len > nUTF8Count )
				return nUTF8LenSoFar;
			nUTF8Len = nUTF8LenSoFar;
		}
		EncodeCharUTF8( nUChar, pszUTF8, nUTF8Len );
	}
	if ( pszUTF8 && nUTF8Len < nUTF8Count )
		pszUTF8[nUTF8Len] = 0;
	return nUTF8Len;
}

int UTF8To16( unsigned short* pwszUTF16, const char* pszUTF8, int nUTF8Count )
{
	// Supports the same arguments as mbstowcs
	// the pszUTF8 source must be a UTF-8 string which will be processed up to NULL-terminator or nUTF8Count
	// if pwszUTF16 is NULL, the number of UTF-16 chars required is returned
	// nUTF8Count is maximum UTF-8 bytes to convert and should include NULL if NULL desired in result
	// if pwszUTF16 is not NULL it is filled with the result string and it must be large enough
	// result will be NULL-terminated if NULL encountered in pszUTF8 before nUTF8Count
	// and the number of UTF-8 bytes converted is returned
	//
	const char* pszPosUTF8 = pszUTF8;
	const char* pszUTF8End = pszUTF8 + nUTF8Count;
	int nUChar, nUTF8Len = 0, nUTF16Len = 0;
	while ( pszPosUTF8 != pszUTF8End )
	{
		nUChar = DecodeCharUTF8( pszPosUTF8, pszUTF8End );
		if ( ! nUChar )
		{
			if ( pwszUTF16 )
				pwszUTF16[nUTF16Len] = 0;
			break;
		}
		else if ( nUChar == -1 )
			nUChar = '?';

		// Encode UTF-16
		EncodeCharUTF16( nUChar, pwszUTF16, nUTF16Len );
	}
	nUTF8Len = (int)(pszPosUTF8 - pszUTF8);
	if ( ! pwszUTF16 )
		return nUTF16Len;
	return nUTF8Len;
}









