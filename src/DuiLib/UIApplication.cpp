#include "stdafx.h"
#include "UIApplication.h"
namespace DuiLib
{
	CApplicationUI* CApplicationUI::s_application=NULL;

	CApplicationUI::CApplicationUI(HINSTANCE hins)
	{
		ASSERT(!s_application);
		s_application=this;
		CPaintManagerUI::SetInstance(hins);
		m_lua.setGlobal("UI",m_lua.newTable());

		LBIND_REGISTER_CLASS(CApplicationUI,&m_lua);
		LBIND_REGISTER_CLASS(CWindowUI,&m_lua);
		LBIND_REGISTER_CLASS(CControlUI,&m_lua);
		LBIND_REGISTER_CLASS(CLabelUI,&m_lua);
		LBIND_REGISTER_CLASS(CButtonUI,&m_lua);
		LBIND_REGISTER_CLASS(COptionUI,&m_lua);
		LBIND_REGISTER_CLASS(CTextUI,&m_lua);
		LBIND_REGISTER_CLASS(CProgressUI,&m_lua);
		LBIND_REGISTER_CLASS(CSliderUI,&m_lua);
		LBIND_REGISTER_CLASS(CEditUI,&m_lua);
		LBIND_REGISTER_CLASS(CScrollBarUI,&m_lua);

		LBIND_REGISTER_CLASS(CContainerUI,&m_lua);
		LBIND_REGISTER_CLASS(CVerticalLayoutUI,&m_lua);
		LBIND_REGISTER_CLASS(CHorizontalLayoutUI,&m_lua);
		LBIND_REGISTER_CLASS(CTileLayoutUI,&m_lua);
		LBIND_REGISTER_CLASS(CTabLayoutUI,&m_lua);
	}

	CApplicationUI::~CApplicationUI()
	{
		s_application=NULL;
	}

	void CApplicationUI::MessageLoop()
	{
		MSG msg = { 0 };
		while( ::GetMessage(&msg, NULL, 0, 0) ) {
			if( !CPaintManagerUI::TranslateMessage(&msg) ) {
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}
		}
	}

	LuaState* CApplicationUI::GetLuaState()
	{
		return &m_lua;
	}













}




















