#include "stdafx.h"
#include "UIApplication.h"

#ifdef LUV_SUPPORT
#include "luv/luv.h"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "IPHLPAPI.lib")  
#pragma comment(lib, "Psapi.lib")  
#pragma comment(lib, "Userenv.lib")  


#endif

namespace DuiLib
{
	CApplicationUI* CApplicationUI::s_application=NULL;

	CApplicationUI::CApplicationUI(HINSTANCE hins)
	{
#ifdef LUV_SUPPORT
		luaopen_luv(m_lua.getLuaState());
		lua_setglobal(m_lua.getLuaState(),"uv");
#endif
		ASSERT(!s_application);
		m_threadId=GetCurrentThreadId();
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
		LBIND_REGISTER_CLASS(CComboUI,&m_lua);
		LBIND_REGISTER_CLASS(CRichEditUI,&m_lua);
		LBIND_REGISTER_CLASS(CDialogBuilder,&m_lua);
	}

	CApplicationUI::~CApplicationUI()
	{
		s_application=NULL;
	}

#ifdef LUV_SUPPORT
	void CALLBACK CApplicationUI::LuvWorkTimerProc(HWND hWnd,UINT nMsg,UINT nTimerid,DWORD dwTime)  
	{
		if(s_application)
			luv_do_loop_work(s_application->m_lua.getLuaState());
	}
#endif


	void CApplicationUI::MessageLoop()
	{
#ifdef LUV_SUPPORT
		SetTimer(NULL,0,10,LuvWorkTimerProc);
#endif
		MSG msg = { 0 };
		while( ::GetMessage(&msg, NULL, 0, 0) ) 
		{
			RefCountedPtr<IRunbaleUI> runable=GetRunable();
			if (runable.get())
				runable->Run(&m_lua);

			if(msg.message!=WM_ACTIVATE_THREAD && !CPaintManagerUI::TranslateMessage(&msg) ) {
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}
		}
	}

	LuaState* CApplicationUI::GetLuaState()
	{
		return &m_lua;
	}



	void CApplicationUI::PostRunable(RefCountedPtr<IRunbaleUI> runable)
	{
		base::CritScope lock(&m_queueLock);
		m_runableQueue.push(runable);
		PostThreadMessage(m_threadId,WM_ACTIVATE_THREAD,0,0);
	}

	RefCountedPtr<IRunbaleUI> CApplicationUI::GetRunable()
	{
		RefCountedPtr<IRunbaleUI> runable;
		base::CritScope lock(&m_queueLock);
		if(!m_runableQueue.empty())
		{
			runable=m_runableQueue.front();
			m_runableQueue.pop();
		}
		return runable;
	}


}




















