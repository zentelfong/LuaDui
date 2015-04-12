#ifndef __UIDLGBUILDER_H__
#define __UIDLGBUILDER_H__

#pragma once

namespace DuiLib {

class IDialogBuilderCallback
{
public:
    virtual CControlUI* CreateControl(LPCTSTR pstrClass) = 0;
};


class UILIB_API CDialogBuilder
{
public:
	LBIND_BASE_CLASS_DEFINE(CDialogBuilder);

    CDialogBuilder(CPaintManagerUI* mgr);
    CControlUI* Create(STRINGorID xml, LPCTSTR type = NULL, IDialogBuilderCallback* pCallback = NULL,CControlUI* pParent = NULL);

    CControlUI* Create(IDialogBuilderCallback* pCallback = NULL,CControlUI* pParent = NULL);

	bool LoadFile(LPCTSTR file);
	bool LoadString(LPCWSTR str);
	bool LoadString(LPCSTR str);

    CMarkup* GetMarkup();

	LPCTSTR GetLastError() const{return m_xml.GetLastError();}

	CPaintManagerUI* GetManager(){return m_pMgr;}
private:
    CControlUI* _Parse(XmlNode parent, CControlUI* pParent = NULL);
	CPaintManagerUI* m_pMgr;
    CMarkup m_xml;
    IDialogBuilderCallback* m_pCallback;
    LPCTSTR m_pstrtype;
};

} // namespace DuiLib

#endif // __UIDLGBUILDER_H__
