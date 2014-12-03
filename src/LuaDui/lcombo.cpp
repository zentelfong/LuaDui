#include "StdAfx.h"
#include "lutil.h"

using namespace DuiLib;


namespace lbindcombo
{
using namespace lbind;


LBIND_DEFINE_FUNC(CComboUI,GetDropBoxAttributeList)
	return L.lreturn(pThis->GetDropBoxAttributeList());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetDropBoxAttributeList)
	pThis->SetDropBoxAttributeList(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetDropBoxSize)
	return L.lreturn(toLua(L,pThis->GetDropBoxSize()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetDropBoxSize)
	pThis->SetDropBoxSize(toSize(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetCurSel)
	return L.lreturn(pThis->GetCurSel());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SelectItem)
	pThis->SelectItem(arg[2].toInt(),arg[3].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetTextPadding)
	return L.lreturn(toLua(L,pThis->GetTextPadding()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetTextPadding)
	pThis->SetTextPadding(toRect(arg[2]));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CComboUI,GetNormalImage)
	return L.lreturn(pThis->GetNormalImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetNormalImage)
	pThis->SetNormalImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CComboUI,GetHotImage)
	return L.lreturn(pThis->GetHotImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetHotImage)
	pThis->SetHotImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

	


LBIND_DEFINE_FUNC(CComboUI,GetPushedImage)
	return L.lreturn(pThis->GetPushedImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetPushedImage)
	pThis->SetPushedImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CComboUI,GetFocusedImage)
	return L.lreturn(pThis->GetFocusedImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetFocusedImage)
	pThis->SetFocusedImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetDisabledImage)
	return L.lreturn(pThis->GetDisabledImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetDisabledImage)
	pThis->SetDisabledImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetItemTextStyle)
	pThis->SetItemTextStyle(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetItemFont)
	pThis->SetItemFont(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CComboUI,GetItemTextPadding)
	return L.lreturn(toLua(L,pThis->GetItemTextPadding()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetItemTextPadding)
	pThis->SetItemTextPadding(toRect(arg[2]));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CComboUI,SetItemTextColor)
	pThis->SetItemTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetItemTextColor)
	return L.lreturn(pThis->GetItemTextColor());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CComboUI,SetItemBkColor)
	pThis->SetItemBkColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetItemBkColor)
	return L.lreturn(pThis->GetItemBkColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetItemBkImage)
	pThis->SetItemBkImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetItemBkImage)
	return L.lreturn(pThis->GetItemBkImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetAlternateBk)
	pThis->SetAlternateBk(arg[2].toBool());
LBIND_END_DEFINE_FUNC



LBIND_DEFINE_FUNC(CComboUI,IsAlternateBk)
	return L.lreturn(pThis->IsAlternateBk());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetSelectedItemTextColor)
	pThis->SetSelectedItemTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetSelectedItemTextColor)
	return L.lreturn(pThis->GetSelectedItemTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetSelectedItemBkColor)
	pThis->SetSelectedItemBkColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetSelectedItemBkColor)
	return L.lreturn(pThis->GetSelectedItemBkColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetSelectedItemImage)
	pThis->SetSelectedItemImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetSelectedItemImage)
	return L.lreturn(pThis->GetSelectedItemImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetHotItemTextColor)
	pThis->SetHotItemTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetHotItemTextColor)
	return L.lreturn(pThis->GetHotItemTextColor());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CComboUI,SetHotItemBkColor)
	pThis->SetHotItemBkColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetHotItemBkColor)
	return L.lreturn(pThis->GetHotItemBkColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetHotItemImage)
	pThis->SetHotItemImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetHotItemImage)
	return L.lreturn(pThis->GetHotItemImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetDisabledItemTextColor)
	pThis->SetDisabledItemTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetDisabledItemTextColor)
	return L.lreturn(pThis->GetDisabledItemTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetDisabledItemBkColor)
	pThis->SetDisabledItemBkColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetDisabledItemBkColor)
	return L.lreturn(pThis->GetDisabledItemBkColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetDisabledItemImage)
	return L.lreturn(pThis->GetDisabledItemImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetDisabledItemImage)
	pThis->SetDisabledItemImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetItemLineColor)
	pThis->SetItemLineColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,GetItemLineColor)
	return L.lreturn(pThis->GetItemLineColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,SetItemShowHtml)
	pThis->SetItemShowHtml(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CComboUI,IsItemShowHtml)
	return L.lreturn(pThis->IsItemShowHtml());
LBIND_END_DEFINE_FUNC


}


LBIND_BEGIN_DEFINE_LIB(CComboUI)
	{"dropBoxAttributeList",lbindcombo::GetDropBoxAttributeList},
	{"setDropBoxAttributeList",lbindcombo::SetDropBoxAttributeList},
	{"dropBoxSize",lbindcombo::GetDropBoxSize},
	{"setDropBoxSize",lbindcombo::SetDropBoxSize},
	{"curSel",lbindcombo::GetCurSel},
	{"selectItem",lbindcombo::SelectItem},
	{"textPadding",lbindcombo::GetTextPadding},
	{"setTextPadding",lbindcombo::SetTextPadding},
	{"normalImage",lbindcombo::GetNormalImage},
	{"setNormalImage",lbindcombo::SetNormalImage},
	{"hotImage",lbindcombo::GetHotImage},
	{"setHotImage",lbindcombo::SetHotImage},
	{"pushedImage",lbindcombo::GetPushedImage},
	{"setPushedImage",lbindcombo::SetPushedImage},
	{"focusedImage",lbindcombo::GetFocusedImage},
	{"setFocusedImage",lbindcombo::SetFocusedImage},
	{"disabledImage",lbindcombo::GetDisabledImage},
	{"setDisabledImage",lbindcombo::SetDisabledImage},

	{"setItemTextStyle",lbindcombo::SetItemTextStyle},
	{"setItemFont",lbindcombo::SetItemFont},
	{"itemTextPadding",lbindcombo::GetItemTextPadding},
	{"setItemTextPadding",lbindcombo::SetItemTextPadding},
	{"setItemTextColor",lbindcombo::SetItemTextColor},
	{"itemTextColor",lbindcombo::GetItemTextColor},
	{"setItemBkColor",lbindcombo::SetItemBkColor},
	{"itemBkColor",lbindcombo::GetItemBkColor},
	{"setItemBkImage",lbindcombo::SetItemBkImage},
	{"itemBkImage",lbindcombo::GetItemBkImage},
	{"setAlternateBk",lbindcombo::SetAlternateBk},

	{"isAlternateBk",lbindcombo::IsAlternateBk},
	{"setSelectedItemTextColor",lbindcombo::SetSelectedItemTextColor},
	{"selectedItemTextColor",lbindcombo::GetSelectedItemTextColor},
	{"setSelectedItemBkColor",lbindcombo::SetSelectedItemBkColor},
	{"selectedItemBkColor",lbindcombo::GetSelectedItemBkColor},
	{"setSelectedItemImage",lbindcombo::SetSelectedItemImage},
	{"selectedItemImage",lbindcombo::GetSelectedItemImage},
	{"setHotItemTextColor",lbindcombo::SetHotItemTextColor},
	{"hotItemTextColor",lbindcombo::GetHotItemTextColor},
	{"setHotItemBkColor",lbindcombo::SetHotItemBkColor},
	{"hotItemImage",lbindcombo::GetHotItemImage},
	{"setHotItemImage",lbindcombo::SetHotItemImage},
	{"setDisabledItemTextColor",lbindcombo::SetDisabledItemTextColor},
	{"disabledItemTextColor",lbindcombo::GetDisabledItemTextColor},
	{"setDisabledItemBkColor",lbindcombo::SetDisabledItemBkColor},
	{"disabledItemBkColor",lbindcombo::GetDisabledItemBkColor},

	{"disabledItemImage",lbindcombo::GetDisabledItemImage},
	{"setDisabledItemImage",lbindcombo::SetDisabledItemImage},
	{"setItemLineColor",lbindcombo::SetItemLineColor},
	{"itemLineColor",lbindcombo::GetItemLineColor},
	{"setItemShowHtml",lbindcombo::SetItemShowHtml},
	{"isItemShowHtml",lbindcombo::IsItemShowHtml},
LBIND_END_DEFINE_LIB

















