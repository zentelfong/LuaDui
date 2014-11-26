#pragma once


// Supports the same arguments as wcstombs
// the pwszUTF16 source must be a NULL-terminated UTF-16 string
// if pszUTF8 is NULL, the number of bytes required is returned and nUTF8Count is ignored
// otherwise pszUTF8 is filled with the result string and NULL-terminated if nUTF8Count allows
// nUTF8Count is the byte size of pszUTF8 and must be large enough for the NULL if NULL desired
// and the number of bytes (excluding NULL) is returned
int UTF16To8( char *pszUTF8, const unsigned short* pwszUTF16, int nUTF8Count );


// Supports the same arguments as mbstowcs
// the pszUTF8 source must be a UTF-8 string which will be processed up to NULL-terminator or nUTF8Count
// if pwszUTF16 is NULL, the number of UTF-16 chars required is returned
// nUTF8Count is maximum UTF-8 bytes to convert and should include NULL if NULL desired in result
// if pwszUTF16 is not NULL it is filled with the result string and it must be large enough
// result will be NULL-terminated if NULL encountered in pszUTF8 before nUTF8Count
// and the number of UTF-8 bytes converted is returned
int UTF8To16( unsigned short* pwszUTF16, const char* pszUTF8, int nUTF8Count );




template<unsigned int BUFSZ=128>
class UtfBuffer
{
public:
	UtfBuffer():m_bufPtr(m_stackBuf)
	{}

	~UtfBuffer()
	{
		if(m_bufPtr!=m_stackBuf)
			::free(m_bufPtr);
	}

	void * malloc(size_t size)
	{
		if(BUFSZ<size)
		{
			if(m_bufPtr!=m_stackBuf)
			{
				m_bufPtr=::realloc(m_bufPtr,size);
			}
			else
				m_bufPtr=::malloc(size);

			return m_bufPtr;
		}
		else
			return m_bufPtr;

	}

	void * getBuf()
	{
		return m_bufPtr;
	}
	
private:
	unsigned char m_stackBuf[BUFSZ];
	void * m_bufPtr;
};







