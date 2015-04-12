#include "StdAfx.h"

#ifndef TRACE
#define TRACE
#endif

///////////////////////////////////////////////////////////////////////////////////////
DECLARE_HANDLE(HZIP);	// An HZIP identifies a zip file that has been opened
typedef DWORD ZRESULT;
typedef struct
{ 
    int index;                 // index of this file within the zip
    char name[MAX_PATH];       // filename within the zip
    DWORD attr;                // attributes, as in GetFileAttributes.
    FILETIME atime,ctime,mtime;// access, create, modify filetimes
    long comp_size;            // sizes of item, compressed and uncompressed. These
    long unc_size;             // may be -1 if not yet known (e.g. being streamed in)
} ZIPENTRY;
typedef struct
{ 
    int index;                 // index of this file within the zip
    TCHAR name[MAX_PATH];      // filename within the zip
    DWORD attr;                // attributes, as in GetFileAttributes.
    FILETIME atime,ctime,mtime;// access, create, modify filetimes
    long comp_size;            // sizes of item, compressed and uncompressed. These
    long unc_size;             // may be -1 if not yet known (e.g. being streamed in)
} ZIPENTRYW;
#define OpenZip OpenZipU
#define CloseZip(hz) CloseZipU(hz)
extern HZIP OpenZipU(void *z,unsigned int len,DWORD flags);
extern ZRESULT CloseZipU(HZIP hz);
#ifdef _UNICODE
#define ZIPENTRY ZIPENTRYW
#define GetZipItem GetZipItemW
#define FindZipItem FindZipItemW
#else
#define GetZipItem GetZipItemA
#define FindZipItem FindZipItemA
#endif
extern ZRESULT GetZipItemA(HZIP hz, int index, ZIPENTRY *ze);
extern ZRESULT GetZipItemW(HZIP hz, int index, ZIPENTRYW *ze);
extern ZRESULT FindZipItemA(HZIP hz, const TCHAR *name, bool ic, int *index, ZIPENTRY *ze);
extern ZRESULT FindZipItemW(HZIP hz, const TCHAR *name, bool ic, int *index, ZIPENTRYW *ze);
extern ZRESULT UnzipItem(HZIP hz, int index, void *dst, unsigned int len, DWORD flags);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace DuiLib
{


CMarkup::CMarkup(LPCTSTR pstrXML)
	:m_pstrXML(NULL)
{
	if( pstrXML != NULL ) Load(pstrXML);
}


CMarkup::~CMarkup(void)
{
	Release();
}

bool CMarkup::_Parse()
{
	if (!m_pstrXML)
		return false;
    pugi::xml_parse_result result = m_parser.load_string(m_pstrXML);

	m_error = result.description();
	return result.status == pugi::status_ok;
}


bool CMarkup::Load(LPCTSTR pstrXML)
{
    Release();
    SIZE_T cchLen = _tcslen(pstrXML) + 1;
    m_pstrXML = static_cast<LPTSTR>(malloc(cchLen * sizeof(TCHAR)));
    ::CopyMemory(m_pstrXML, pstrXML, cchLen * sizeof(TCHAR));
    bool bRes = _Parse();
    if( !bRes ) Release();
    return bRes;
}

bool CMarkup::LoadFromMem(BYTE* pByte, DWORD dwSize, int encoding)
{
#ifdef _UNICODE
    if (encoding == XMLFILE_ENCODING_UTF8)
    {
        if( dwSize >= 3 && pByte[0] == 0xEF && pByte[1] == 0xBB && pByte[2] == 0xBF ) 
        {
            pByte += 3; dwSize -= 3;
        }
        DWORD nWide = ::MultiByteToWideChar( CP_UTF8, 0, (LPCSTR)pByte, dwSize, NULL, 0 );

        m_pstrXML = static_cast<LPTSTR>(malloc((nWide + 1)*sizeof(TCHAR)));
        ::MultiByteToWideChar( CP_UTF8, 0, (LPCSTR)pByte, dwSize, m_pstrXML, nWide );
        m_pstrXML[nWide] = _T('\0');
    }
    else if (encoding == XMLFILE_ENCODING_ASNI)
    {
        DWORD nWide = ::MultiByteToWideChar( CP_ACP, 0, (LPCSTR)pByte, dwSize, NULL, 0 );

        m_pstrXML = static_cast<LPTSTR>(malloc((nWide + 1)*sizeof(TCHAR)));
        ::MultiByteToWideChar( CP_ACP, 0, (LPCSTR)pByte, dwSize, m_pstrXML, nWide );
        m_pstrXML[nWide] = _T('\0');
    }
    else
    {
        if ( dwSize >= 2 && ( ( pByte[0] == 0xFE && pByte[1] == 0xFF ) || ( pByte[0] == 0xFF && pByte[1] == 0xFE ) ) )
        {
            dwSize = dwSize / 2 - 1;

            if ( pByte[0] == 0xFE && pByte[1] == 0xFF )
            {
                pByte += 2;

                for ( DWORD nSwap = 0 ; nSwap < dwSize ; nSwap ++ )
                {
                    register CHAR nTemp = pByte[ ( nSwap << 1 ) + 0 ];
                    pByte[ ( nSwap << 1 ) + 0 ] = pByte[ ( nSwap << 1 ) + 1 ];
                    pByte[ ( nSwap << 1 ) + 1 ] = nTemp;
                }
            }
            else
            {
                pByte += 2;
            }

            m_pstrXML = static_cast<LPTSTR>(malloc((dwSize + 1)*sizeof(TCHAR)));
            ::CopyMemory( m_pstrXML, pByte, dwSize * sizeof(TCHAR) );
            m_pstrXML[dwSize] = _T('\0');

            pByte -= 2;
        }
    }
#else // !_UNICODE
    if (encoding == XMLFILE_ENCODING_UTF8)
    {
        if( dwSize >= 3 && pByte[0] == 0xEF && pByte[1] == 0xBB && pByte[2] == 0xBF ) 
        {
            pByte += 3; dwSize -= 3;
        }
        DWORD nWide = ::MultiByteToWideChar( CP_UTF8, 0, (LPCSTR)pByte, dwSize, NULL, 0 );

        LPWSTR w_str = static_cast<LPWSTR>(malloc((nWide + 1)*sizeof(WCHAR)));
        ::MultiByteToWideChar( CP_UTF8, 0, (LPCSTR)pByte, dwSize, w_str, nWide );
        w_str[nWide] = L'\0';

        DWORD wide = ::WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)w_str, nWide, NULL, 0, NULL, NULL);

        m_pstrXML = static_cast<LPTSTR>(malloc((wide + 1)*sizeof(TCHAR)));
        ::WideCharToMultiByte( CP_ACP, 0, (LPCWSTR)w_str, nWide, m_pstrXML, wide, NULL, NULL);
        m_pstrXML[wide] = _T('\0');

        free(w_str);
    }
    else if (encoding == XMLFILE_ENCODING_UNICODE)
    {
        if ( dwSize >= 2 && ( ( pByte[0] == 0xFE && pByte[1] == 0xFF ) || ( pByte[0] == 0xFF && pByte[1] == 0xFE ) ) )
        {
            dwSize = dwSize / 2 - 1;

            if ( pByte[0] == 0xFE && pByte[1] == 0xFF )
            {
                pByte += 2;

                for ( DWORD nSwap = 0 ; nSwap < dwSize ; nSwap ++ )
                {
                    register CHAR nTemp = pByte[ ( nSwap << 1 ) + 0 ];
                    pByte[ ( nSwap << 1 ) + 0 ] = pByte[ ( nSwap << 1 ) + 1 ];
                    pByte[ ( nSwap << 1 ) + 1 ] = nTemp;
                }
            }
            else
            {
                pByte += 2;
            }

            DWORD nWide = ::WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)pByte, dwSize, NULL, 0, NULL, NULL);
            m_pstrXML = static_cast<LPTSTR>(malloc((nWide + 1)*sizeof(TCHAR)));
            ::WideCharToMultiByte( CP_ACP, 0, (LPCWSTR)pByte, dwSize, m_pstrXML, nWide, NULL, NULL);
            m_pstrXML[nWide] = _T('\0');

            pByte -= 2;
        }
    }
    else
    {
        m_pstrXML = static_cast<LPTSTR>(malloc((dwSize + 1)*sizeof(TCHAR)));
        ::CopyMemory( m_pstrXML, pByte, dwSize * sizeof(TCHAR) );
        m_pstrXML[dwSize] = _T('\0');
    }
#endif // _UNICODE

    bool bRes = _Parse();
    if( !bRes ) Release();
    return bRes;
}

bool CMarkup::LoadFromFile(LPCTSTR pstrFilename, int encoding)
{
    Release();
    CStdString sFile = CPaintManagerUI::GetResourcePath();
    if( CPaintManagerUI::GetResourceZip().IsEmpty() ) {
        sFile += pstrFilename;
        HANDLE hFile = ::CreateFile(sFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if( hFile == INVALID_HANDLE_VALUE ) return _Failed("Error opening file");
        DWORD dwSize = ::GetFileSize(hFile, NULL);
        if( dwSize == 0 ) return _Failed("File is empty");
        if ( dwSize > 4096*1024 ) return _Failed("File too large");

        DWORD dwRead = 0;
        BYTE* pByte = new BYTE[ dwSize ];
        ::ReadFile( hFile, pByte, dwSize, &dwRead, NULL );
        ::CloseHandle( hFile );

        if( dwRead != dwSize ) {
            delete[] pByte;
            Release();
            return _Failed("Could not read file");
        }
        bool ret = LoadFromMem(pByte, dwSize, encoding);
        delete[] pByte;

        return ret;
    }
    else {
        sFile += CPaintManagerUI::GetResourceZip();
        HZIP hz = NULL;
        if( CPaintManagerUI::IsCachedResourceZip() ) hz = (HZIP)CPaintManagerUI::GetResourceZipHandle();
        else hz = OpenZip((void*)sFile.GetString(), 0, 2);
        if( hz == NULL ) return _Failed("Error opening zip file");
        ZIPENTRY ze; 
        int i; 
        if( FindZipItem(hz, pstrFilename, true, &i, &ze) != 0 ) return _Failed("Could not find ziped file");
        DWORD dwSize = ze.unc_size;
        if( dwSize == 0 ) return _Failed("File is empty");
        if ( dwSize > 4096*1024 ) return _Failed("File too large");
        BYTE* pByte = new BYTE[ dwSize ];
        int res = UnzipItem(hz, i, pByte, dwSize, 3);
        if( res != 0x00000000 && res != 0x00000600) {
            delete[] pByte;
            if( !CPaintManagerUI::IsCachedResourceZip() ) CloseZip(hz);
            return _Failed("Could not unzip file");
        }
        if( !CPaintManagerUI::IsCachedResourceZip() ) CloseZip(hz);
        bool ret = LoadFromMem(pByte, dwSize, encoding);
        delete[] pByte;

        return ret;
    }
}


void CMarkup::Release()
{
	if( m_pstrXML != NULL ) free(m_pstrXML);
	m_pstrXML=NULL;
	m_parser.reset();
}

LPCTSTR CMarkup::GetLastError() const
{
	return m_error;
}

bool CMarkup::IsValid() const
{
	return m_parser.root();
}

XmlNode CMarkup::GetRoot()
{
	return m_parser.root();
}


bool CMarkup::_Failed(const char* pstrError)
{
    // Register last error
	printf("%s",pstrError);
	m_error=pstrError;
    return false; // Always return 'false'
}










}