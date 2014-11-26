#include "StdAfx.h"
using namespace DuiLib;

namespace lbind
{
LBIND_DEFINE_STATIC_FUNC(CWindowUI,Create)
	//´´½¨´°¿Ú
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
	bindPtr->ShowWindow(arg[2].toBool(),arg[3].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,Close)
	bindPtr->Close();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,CenterWindow)
	bindPtr->CenterWindow();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CWindowUI,ResizeClient)
	bindPtr->ResizeClient(arg[2].toInt(),arg[3].toInt());
LBIND_END_DEFINE_FUNC


}

LBIND_BEGIN_DEFINE_LIB(CWindowUI)
	{"create",lbind::Create},
	{"showWindow",lbind::ShowWindow},
	{"close",lbind::Close},
	{"centerWindow",lbind::CenterWindow},
	{"resizeClient",lbind::ResizeClient},
LBIND_END_DEFINE_LIB



