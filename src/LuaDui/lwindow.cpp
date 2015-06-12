#include "StdAfx.h"
using namespace DuiLib;

namespace lbind
{
LBIND_DEFINE_STATIC_FUNC(CWindowUI,Create)
	//创建窗口
	CHECK_ARG_TABLE(1);
	LuaTable param=arg[1];
	CWindowUI* wnd=new CWindowUI;

	LuaObject type=param["type"];
	DWORD wndType=UI_WNDSTYLE_FRAME;
	CWindowUI* parent=CWindowUI::_lbindLuaToC(param["parent"]);
	CStdString skinXml=param["res"].toString();

	if (type=="popup")
	{
		wndType=UI_WNDSTYLE_DIALOG;
	}
	else if (type=="child")
	{
		wndType=UI_WNDSTYLE_CHILD;
	}

	wnd->SetSkinXml(skinXml);
	wnd->Create(parent? parent->GetHWND():NULL,CStdString(param["name"].toString()), wndType, WS_EX_STATICEDGE | WS_EX_APPWINDOW,param["x"].toInt(), param["y"].toInt(),param["w"].toInt(),param["h"].toInt());
	return L.lreturn(wnd->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CWindowUI,ShowWindow)
	pThis->ShowWindow(arg[2].toBool(),arg[3].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,ShowMin)
	::ShowWindow(pThis->GetHWND(),SW_MINIMIZE);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,ShowMax)
	::ShowWindow(pThis->GetHWND(),SW_MAXIMIZE);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,ShowRestore)
	::ShowWindow(pThis->GetHWND(),SW_RESTORE);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,Close)
	pThis->Close();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,CenterWindow)
	pThis->CenterWindow();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,ResizeClient)
	pThis->ResizeClient(arg[2].toInt(),arg[3].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CWindowUI,FindControl)
	CControlUI* ctl=pThis->FindControl(CStdString(arg[2].toString()));
	if(ctl)
		return L.lreturn(ctl->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC

//创建builder
LBIND_DEFINE_FUNC(CWindowUI,CreateBuilder)
	CDialogBuilder* builder=new CDialogBuilder(pThis->GetManager());
	return L.lreturn(builder->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC

}

LBIND_BEGIN_DEFINE_LIB(CWindowUI)
	{"create",lbind::Create},
	{"showWindow",lbind::ShowWindow},
	{"showMin",lbind::ShowMin},
	{"showMax",lbind::ShowMax},
	{"showRestore",lbind::ShowRestore},

	{"close",lbind::Close},
	{"centerWindow",lbind::CenterWindow},
	{"resizeClient",lbind::ResizeClient},
	{"findControl",lbind::FindControl},
	{"createBuilder",lbind::CreateBuilder},
LBIND_END_DEFINE_LIB



