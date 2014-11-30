#include "StdAfx.h"
#include "lutil.h"

using namespace DuiLib;

namespace lbindcontainer
{
using namespace lbind;

LBIND_DEFINE_FUNC(CContainerUI,GetItemAt)
	CControlUI* child=pThis->GetItemAt(arg[2].toInt());
	if(child)
		return L.lreturn(child->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetItemIndex)
	int idx=pThis->GetItemIndex(CControlUI::_lbindLuaToC(arg[2]));
	return L.lreturn(idx);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,SetItemIndex)
	CControlUI* ctl=CControlUI::_lbindLuaToC(arg[2]);
	int idx=arg[3].toInt();
	pThis->SetItemIndex(ctl,idx);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetCount)
	return L.lreturn(pThis->GetCount());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,Add)
	CControlUI* ctl=CControlUI::_lbindLuaToC(arg[2]);
	bool rtn=pThis->Add(ctl);
	return L.lreturn(rtn);
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CContainerUI,AddAt)
	CControlUI* ctl=CControlUI::_lbindLuaToC(arg[2]);
	int idx=arg[3].toInt();
	bool rtn=pThis->AddAt(ctl,idx);
	return L.lreturn(rtn);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,Remove)
	CControlUI* ctl=CControlUI::_lbindLuaToC(arg[2]);
	bool rtn=pThis->Remove(ctl);
	return L.lreturn(rtn);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,RemoveAt)
	int idx=arg[2].toInt();
	bool rtn=pThis->RemoveAt(idx);
	return L.lreturn(rtn);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,RemoveAll)
	pThis->RemoveAll();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetInset)
	return L.lreturn(toLua(L,pThis->GetInset()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,SetInset)
	pThis->SetInset(toRect(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetChildPadding)
	return L.lreturn(pThis->GetChildPadding());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,SetChildPadding)
	pThis->SetChildPadding(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,IsAutoDestroy)
	return L.lreturn(pThis->IsAutoDestroy());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,SetAutoDestroy)
	pThis->SetAutoDestroy(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,IsDelayedDestroy)
	return L.lreturn(pThis->IsDelayedDestroy());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,SetDelayedDestroy)
	pThis->SetDelayedDestroy(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,IsMouseChildEnabled)
	return L.lreturn(pThis->IsMouseChildEnabled());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,SetMouseChildEnabled)
	pThis->SetMouseChildEnabled(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetScrollPos)
	return L.lreturn(toLua(L,pThis->GetScrollPos()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetScrollRange)
	return L.lreturn(toLua(L,pThis->GetScrollRange()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,SetScrollPos)
	pThis->SetScrollPos(toSize(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,LineUp)
	pThis->LineUp();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,LineDown)
	pThis->LineDown();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,PageUp)
	pThis->PageUp();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,PageDown)
	pThis->PageDown();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,HomeUp)
	pThis->HomeUp();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,EndDown)
	pThis->EndDown();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,LineLeft)
	pThis->LineLeft();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,LineRight)
	pThis->LineRight();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,PageLeft)
	pThis->PageLeft();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,PageRight)
	pThis->PageRight();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,HomeLeft)
	pThis->HomeLeft();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,EndRight)
	pThis->EndRight();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,EnableScrollBar)
	pThis->EnableScrollBar(arg[2].toBool(),arg[3].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetVerticalScrollBar)
	CControlUI* scrollbar=pThis->GetVerticalScrollBar();
	return L.lreturn(scrollbar->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CContainerUI,GetHorizontalScrollBar)
	CControlUI* scrollbar=pThis->GetHorizontalScrollBar();
	return L.lreturn(scrollbar->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC


}

LBIND_BEGIN_DEFINE_LIB(CContainerUI)
	{"itemAt",lbindcontainer::GetItemAt},
	{"itemIndex",lbindcontainer::GetItemIndex},
	{"setItemIndex",lbindcontainer::SetItemIndex},
	{"count",lbindcontainer::GetCount},
	{"add",lbindcontainer::Add},
	{"addAt",lbindcontainer::AddAt},
	{"remove",lbindcontainer::Remove},
	{"removeAt",lbindcontainer::RemoveAt},
	{"removeAll",lbindcontainer::RemoveAll},
	{"inset",lbindcontainer::GetInset},
	{"setInset",lbindcontainer::SetInset},
	{"childPadding",lbindcontainer::GetChildPadding},
	{"setChildPadding",lbindcontainer::SetChildPadding},
	{"isAutoDestroy",lbindcontainer::IsAutoDestroy},
	{"setAutoDestroy",lbindcontainer::SetAutoDestroy},
	{"isDelayedDestroy",lbindcontainer::IsDelayedDestroy},
	{"setDelayedDestroy",lbindcontainer::SetDelayedDestroy},
	{"isMouseChildEnabled",lbindcontainer::IsMouseChildEnabled},
	{"setMouseChildEnabled",lbindcontainer::SetMouseChildEnabled},
	{"scrollPos",lbindcontainer::GetScrollPos},
	{"scrollRange",lbindcontainer::GetScrollRange},
	{"setScrollPos",lbindcontainer::SetScrollPos},
	{"lineUp",lbindcontainer::LineUp},
	{"lineDown",lbindcontainer::LineDown},
	{"pageUp",lbindcontainer::PageUp},
	{"pageDown",lbindcontainer::PageDown},
	{"homeUp",lbindcontainer::HomeUp},
	{"EndDown",lbindcontainer::EndDown},
	{"lineLeft",lbindcontainer::LineLeft},
	{"lineRight",lbindcontainer::LineRight},
	{"pageLeft",lbindcontainer::PageLeft},
	{"pageRight",lbindcontainer::PageRight},
	{"homeLeft",lbindcontainer::HomeLeft},
	{"endRight",lbindcontainer::EndRight},
	{"enableScrollBar",lbindcontainer::EnableScrollBar},
	{"verticalScrollBar",lbindcontainer::GetVerticalScrollBar},
	{"horizontalScrollBar",lbindcontainer::GetHorizontalScrollBar},

LBIND_END_DEFINE_LIB




namespace lbindverlayout
{

LBIND_DEFINE_FUNC(CVerticalLayoutUI,SetSepHeight)
	pThis->SetSepHeight(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CVerticalLayoutUI,GetSepHeight)
	return L.lreturn(pThis->GetSepHeight());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CVerticalLayoutUI,SetSepImmMode)
	pThis->SetSepImmMode(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CVerticalLayoutUI,IsSepImmMode)
	return L.lreturn(pThis->IsSepImmMode());
LBIND_END_DEFINE_FUNC

}


LBIND_BEGIN_DEFINE_LIB(CVerticalLayoutUI)
	{"setSepHeight",lbindverlayout::SetSepHeight},
	{"sepHeight",lbindverlayout::GetSepHeight},
	{"setSepImmMode",lbindverlayout::SetSepImmMode},
	{"isSepImmMode",lbindverlayout::IsSepImmMode},
LBIND_END_DEFINE_LIB


namespace lbindhorlayout
{

LBIND_DEFINE_FUNC(CHorizontalLayoutUI,SetSepWidth)
	pThis->SetSepWidth(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CHorizontalLayoutUI,GetSepWidth)
	return L.lreturn(pThis->GetSepWidth());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CHorizontalLayoutUI,SetSepImmMode1)
	pThis->SetSepImmMode(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CHorizontalLayoutUI,IsSepImmMode1)
	return L.lreturn(pThis->IsSepImmMode());
LBIND_END_DEFINE_FUNC

}


LBIND_BEGIN_DEFINE_LIB(CHorizontalLayoutUI)
	{"setSepHeight",lbindhorlayout::SetSepWidth},
	{"sepHeight",lbindhorlayout::GetSepWidth},
	{"setSepImmMode",lbindhorlayout::SetSepImmMode1},
	{"isSepImmMode",lbindhorlayout::IsSepImmMode1},
LBIND_END_DEFINE_LIB


namespace lbind
{

LBIND_DEFINE_FUNC(CTileLayoutUI,SetSepWidth)
	pThis->SetItemSize(toSize(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CTileLayoutUI,GetSepWidth)
	return L.lreturn(toLua(L,pThis->GetItemSize()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CTileLayoutUI,SetColumns)
	pThis->SetColumns(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CTileLayoutUI,GetColumns)
	return L.lreturn(pThis->GetColumns());
LBIND_END_DEFINE_FUNC

}


LBIND_BEGIN_DEFINE_LIB(CTileLayoutUI)
	{"SetSepWidth",lbind::SetSepWidth},
	{"sepHeight",lbind::GetSepWidth},
	{"SetColumns",lbind::SetColumns},
	{"GetColumns",lbind::GetColumns},
LBIND_END_DEFINE_LIB


namespace lbind
{
LBIND_DEFINE_FUNC(CTabLayoutUI,SelectItem)
	pThis->SelectItem(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CTabLayoutUI,GetCurSel)
	return L.lreturn(pThis->GetCurSel());
LBIND_END_DEFINE_FUNC

}


LBIND_BEGIN_DEFINE_LIB(CTabLayoutUI)
	{"selectItem",lbind::SelectItem},
	{"curSel",lbind::GetCurSel},
LBIND_END_DEFINE_LIB





























