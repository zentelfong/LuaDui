#include "StdAfx.h"
#include "lutil.h"

using namespace DuiLib;

namespace lbind
{

LBIND_DEFINE_FUNC(CControlUI,GetWindow)
	CWindowUI* wnd=pThis->GetManager()->GetWindow();
	if(wnd)
		return L.lreturn(wnd->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetWindowHandle)
	HWND wnd=pThis->GetManager()->GetPaintWindow();
	if(wnd)
		return L.lreturn((LUA_INTEGER)wnd);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetPos)
	RECT rc=pThis->GetPos();
	return L.lreturn(toLua(L,rc));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetPos)
	RECT rc=toRect(arg[2]);
	pThis->SetPos(rc);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetWidth)
	return L.lreturn(pThis->GetWidth());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetHeight)
	return L.lreturn(pThis->GetHeight());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetX)
	return L.lreturn(pThis->GetX());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetY)
	return L.lreturn(pThis->GetY());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetPadding)
	return L.lreturn(toLua(L,pThis->GetPadding()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetPadding)
	pThis->SetPadding(toRect(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetFixedXY)
	return L.lreturn(toLua(L,pThis->GetFixedXY()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetFixedXY)
	pThis->SetFixedXY(toSize(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetFixedWidth)
	return L.lreturn(pThis->GetFixedWidth());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetFixedWidth)
	pThis->SetFixedWidth(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetFixedHeight)
	return L.lreturn(pThis->GetFixedHeight());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetFixedHeight)
	pThis->SetFixedHeight(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,GetMinWidth)
	return L.lreturn(pThis->GetMinWidth());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetMinWidth)
	pThis->SetMinWidth(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,GetMaxWidth)
	return L.lreturn(pThis->GetMaxWidth());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetMaxWidth)
	pThis->SetMaxWidth(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetMinHeight)
	return L.lreturn(pThis->GetMinHeight());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetMinHeight)
	pThis->SetMinHeight(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,GetMaxHeight)
	return L.lreturn(pThis->GetMaxHeight());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetMaxHeight)
	pThis->SetMaxHeight(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,SetRelativeParentSize)
	pThis->SetRelativeParentSize(toSize(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetRelativePos)
	pThis->SetRelativePos(toSize(arg[2]),toSize(arg[3]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,IsRelativePos)
	return L.lreturn(pThis->IsRelativePos());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,Invalidate)
	pThis->Invalidate();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,IsUpdateNeeded)
	return L.lreturn(pThis->IsUpdateNeeded());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,NeedUpdate)
	pThis->NeedUpdate();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,NeedParentUpdate)
	pThis->NeedParentUpdate();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetToolTip)
	return L.lreturn(pThis->GetToolTip());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetToolTip)
	pThis->SetToolTip(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,GetShortcut)
	return L.lreturn((int)pThis->GetShortcut());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetShortcut)
	pThis->SetShortcut(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,IsContextMenuUsed)
	return L.lreturn((int)pThis->IsContextMenuUsed());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetContextMenuUsed)
	pThis->SetContextMenuUsed(arg[2].toBool());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,GetUserData)
	return L.lreturn(pThis->GetUserData());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetUserData)
	pThis->SetUserData(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetTag)
	return L.lreturn(pThis->GetTag());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetTag)
	pThis->SetTag(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,IsVisible)
	return L.lreturn(pThis->IsVisible());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetVisible)
	pThis->SetVisible(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetInternVisible)
	pThis->SetInternVisible(arg[2].toBool());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,IsEnabled)
	return L.lreturn(pThis->IsEnabled());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetEnabled)
	pThis->SetEnabled(arg[2].toBool());
LBIND_END_DEFINE_FUNC



LBIND_DEFINE_FUNC(CControlUI,IsMouseEnabled)
	return L.lreturn(pThis->IsMouseEnabled());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetMouseEnabled)
	pThis->SetMouseEnabled(arg[2].toBool());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,IsKeyboardEnabled)
	return L.lreturn(pThis->IsKeyboardEnabled());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetKeyboardEnabled)
	pThis->SetKeyboardEnabled(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,IsFocused)
	return L.lreturn(pThis->IsFocused());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetFocus)
	pThis->SetFocus();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,IsFloat)
	return L.lreturn(pThis->IsFloat());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetFloat)
	pThis->SetFloat();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetName)
	return L.lreturn(pThis->GetName());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetName)
	pThis->SetName(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetClass)
	return L.lreturn(pThis->GetClass());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,Activate)
	pThis->Activate();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetParent)
	CControlUI* parent=pThis->GetParent();
	if (parent)
		L.lreturn(parent->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetText)
	return L.lreturn(pThis->GetText());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetText)
	pThis->SetText(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,GetBkColor)
	return L.lreturn(pThis->GetBkColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetBkColor)
	pThis->SetBkColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetBkColor2)
	return L.lreturn(pThis->GetBkColor2());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetBkColor2)
	pThis->SetBkColor2(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetBkColor3)
	return L.lreturn(pThis->GetBkColor3());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetBkColor3)
	pThis->SetBkColor3(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetBkImage)
	return L.lreturn(pThis->GetBkImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetBkImage)
	pThis->SetBkImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetBorderColor)
	return L.lreturn(pThis->GetBorderColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetBorderColor)
	pThis->SetBorderColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetFocusBorderColor)
	return L.lreturn(pThis->GetFocusBorderColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetFocusBorderColor)
	pThis->SetFocusBorderColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,IsColorHSL)
	return L.lreturn(pThis->IsColorHSL());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetColorHSL)
	pThis->SetColorHSL(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetBorderSize)
	return L.lreturn(pThis->GetBorderSize());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetBorderSize)
	pThis->SetBorderSize(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CControlUI,GetBorderRound)
	return L.lreturn(toLua(L,pThis->GetBorderRound()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetBorderRound)
	pThis->SetBorderRound(toSize(arg[2]));
LBIND_END_DEFINE_FUNC



}

LBIND_BEGIN_DEFINE_LIB(CControlUI)
	{"window",lbind::GetWindow},
	{"windowHandle",lbind::GetWindowHandle},
	{"text",lbind::GetText},
	{"setText",lbind::SetText},

	{"activate",lbind::Activate},
	{"parent",lbind::GetParent},

	{"name",lbind::GetName},
	{"setName",lbind::SetName},
	{"className",lbind::GetClass},

	{"pos",lbind::GetPos},
	{"setPos",lbind::SetPos},
	{"width",lbind::GetWidth},
	{"height",lbind::GetHeight},
	{"x",lbind::GetX},
	{"y",lbind::GetY},
	{"padding",lbind::GetPadding},
	{"setPadding",lbind::SetPadding},
	{"fixedXY",lbind::GetFixedXY},
	{"setFixedXY",lbind::SetFixedXY},
	{"fixedWidth",lbind::GetFixedWidth},
	{"setFixedWidth",lbind::SetFixedWidth},
	{"fixedHeight",lbind::GetFixedHeight},
	{"setFixedHeight",lbind::SetFixedHeight},
	{"minWidth",lbind::GetMinWidth},
	{"setMinWidth",lbind::SetMinWidth},
	{"maxWidth",lbind::GetMaxWidth},
	{"setMaxWidth",lbind::SetMaxWidth},
	{"minHeight",lbind::GetMinHeight},
	{"setMinHeight",lbind::SetMinHeight},
	{"maxHeight",lbind::GetMaxHeight},
	{"setMaxHeight",lbind::SetMaxHeight},

	{"setRelativeParentSize",lbind::SetRelativeParentSize},
	{"setRelativePos",lbind::SetRelativePos},
	{"isRelativePos",lbind::IsRelativePos},
	{"invalidate",lbind::Invalidate},
	{"isUpdateNeeded",lbind::IsUpdateNeeded},
	{"needUpdate",lbind::NeedUpdate},
	{"needParentUpdate",lbind::NeedParentUpdate},

	{"toolTip",lbind::GetToolTip},
	{"setToolTip",lbind::SetToolTip},
	{"shortcut",lbind::GetShortcut},
	{"setShortcut",lbind::SetShortcut},
	{"isContextMenuUsed",lbind::IsContextMenuUsed},
	{"setContextMenuUsed",lbind::SetContextMenuUsed},
	{"userData",lbind::GetUserData},
	{"setUserData",lbind::SetUserData},
	{"tag",lbind::GetTag},
	{"setTag",lbind::SetTag},

	{"isVisible",lbind::IsVisible},
	{"setVisible",lbind::SetVisible},
	{"setInternVisible",lbind::SetInternVisible},
	{"isEnabled",lbind::IsEnabled},
	{"setEnabled",lbind::SetEnabled},
	{"isMouseEnabled",lbind::IsMouseEnabled},
	{"setMouseEnabled",lbind::SetMouseEnabled},
	{"isKeyboardEnabled",lbind::IsKeyboardEnabled},
	{"setKeyboardEnabled",lbind::SetKeyboardEnabled},
	{"isFocused",lbind::IsFocused},
	{"setFocus",lbind::SetFocus},
	{"isFloat",lbind::IsFloat},
	{"setFloat",lbind::SetFloat},

	{"bkColor",lbind::GetBkColor},
	{"setBkColor",lbind::SetBkColor},
	{"bkColor2",lbind::GetBkColor2},
	{"setBkColor2",lbind::SetBkColor2},
	{"bkColor3",lbind::GetBkColor3},
	{"setBkColor3",lbind::SetBkColor3},
	{"bkImage",lbind::GetBkImage},
	{"setBkImage",lbind::SetBkImage},

	{"borderColor",lbind::GetBorderColor},
	{"setBorderColor",lbind::SetBorderColor},
	{"focusBorderColor",lbind::GetFocusBorderColor},
	{"setFocusBorderColor",lbind::SetFocusBorderColor},

	{"isColorHSL",lbind::IsColorHSL},
	{"setColorHSL",lbind::SetColorHSL},
	{"borderSize",lbind::GetBorderSize},
	{"setBorderSize",lbind::SetBorderSize},
	{"borderRound",lbind::GetBorderRound},
	{"setBorderRound",lbind::SetBorderRound},
LBIND_END_DEFINE_LIB

















