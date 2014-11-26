#ifndef UIAPPLICATION_H
#define UIAPPLICATION_H

namespace DuiLib
{

class CApplicationUI
{
public:
	LBIND_BASE_CLASS_DEFINE(CApplicationUI);

	CApplicationUI(HINSTANCE hins);
	~CApplicationUI();

	void MessageLoop();
	LuaState* GetLuaState();

	//CPaintManager
	static HINSTANCE GetInstance(){return CPaintManagerUI::GetInstance();}
	static CStdString GetInstancePath(){return CPaintManagerUI::GetInstancePath();}
	static CStdString GetCurrentPath(){return CPaintManagerUI::GetCurrentPath();}
	static HINSTANCE GetResourceDll(){return CPaintManagerUI::GetResourceDll();}
	static const CStdString& GetResourcePath(){return CPaintManagerUI::GetResourcePath();}
	static const CStdString& GetResourceZip(){return CPaintManagerUI::GetResourceZip();}
	static bool IsCachedResourceZip(){return CPaintManagerUI::IsCachedResourceZip();}
	static HANDLE GetResourceZipHandle(){return CPaintManagerUI::GetResourceZipHandle();}
	static void SetInstance(HINSTANCE hInst){CPaintManagerUI::SetInstance(hInst);}
	static void SetCurrentPath(LPCTSTR pStrPath){CPaintManagerUI::SetCurrentPath(pStrPath);}
	static void SetResourceDll(HINSTANCE hInst){CPaintManagerUI::SetResourceDll(hInst);}
	static void SetResourcePath(LPCTSTR pStrPath){CPaintManagerUI::SetResourcePath(pStrPath);}
	static void SetResourceZip(LPVOID pVoid, unsigned int len){CPaintManagerUI::SetResourceZip(pVoid,len);}
	static void SetResourceZip(LPCTSTR pstrZip, bool bCachedResourceZip = false){CPaintManagerUI::SetResourceZip(pstrZip,bCachedResourceZip);}
	static void GetHSL(short* H, short* S, short* L){CPaintManagerUI::GetHSL(H,S,L);}
	static void SetHSL(bool bUseHSL, short H, short S, short L){CPaintManagerUI::SetHSL(bUseHSL,H,S,L);}
	static void ReloadSkin(){CPaintManagerUI::ReloadSkin();}
	static bool LoadPlugin(LPCTSTR pstrModuleName){return CPaintManagerUI::LoadPlugin(pstrModuleName);}
	static CStdPtrArray* GetPlugins(){return CPaintManagerUI::GetPlugins();}

	static CApplicationUI* SharedInstance(){return s_application;}
private:
	LuaEngine m_lua;
	static CApplicationUI* s_application;
};

}
#endif