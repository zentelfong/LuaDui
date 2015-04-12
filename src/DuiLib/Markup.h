#pragma once
#include "xml/pugixml.hpp"
#include "UIString.h"

namespace DuiLib
{
	enum
	{
		XMLFILE_ENCODING_UTF8 = 0,
		XMLFILE_ENCODING_UNICODE = 1,
		XMLFILE_ENCODING_ASNI = 2,
	};

	typedef pugi::xml_document XmlDoc;
	typedef pugi::xml_node XmlNode;
	typedef pugi::xml_attribute XmlAttr;


	class CMarkup
	{
	public:
		CMarkup(LPCTSTR pstrXML = NULL);
		~CMarkup();

		bool Load(LPCTSTR pstrXML);
		bool LoadFromMem(BYTE* pByte, DWORD dwSize, int encoding = XMLFILE_ENCODING_UTF8);
		bool LoadFromFile(LPCTSTR pstrFilename, int encoding = XMLFILE_ENCODING_UTF8);
		void Release();
		
		XmlNode GetRoot();

		bool IsValid() const;
		LPCTSTR GetLastError() const;
	private:
		bool _Parse();
		bool _Failed(const char* pstrError);
		LPTSTR m_pstrXML;
		XmlDoc m_parser;
		CStdString m_error;
	};

}