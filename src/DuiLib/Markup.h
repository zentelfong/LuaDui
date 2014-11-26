#pragma once
#include "rapidxml.hpp"
#include <string>

namespace DuiLib
{
	enum
	{
		XMLFILE_ENCODING_UTF8 = 0,
		XMLFILE_ENCODING_UNICODE = 1,
		XMLFILE_ENCODING_ASNI = 2,
	};

	typedef rapidxml::xml_document<TCHAR> XmlDoc;
	typedef rapidxml::xml_node<TCHAR> XmlNode;
	typedef rapidxml::xml_attribute<TCHAR> XmlAttr;


	class CMarkup
	{
	public:
		CMarkup(LPCTSTR pstrXML = NULL);
		~CMarkup();

		bool Load(LPCTSTR pstrXML);
		bool LoadFromMem(BYTE* pByte, DWORD dwSize, int encoding = XMLFILE_ENCODING_UTF8);
		bool LoadFromFile(LPCTSTR pstrFilename, int encoding = XMLFILE_ENCODING_UTF8);
		void Release();
		const char* GetLastError() const;

		XmlNode* GetRoot();

		bool IsValid() const;

		
	private:
		bool _Parse();
		bool _Failed(const char* pstrError);
		bool m_isValid;
		LPTSTR m_pstrXML;
		XmlDoc m_parser;
		std::string m_error;
	};

}