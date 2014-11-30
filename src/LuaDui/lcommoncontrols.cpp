#include "StdAfx.h"
#include "lutil.h"

using namespace DuiLib;

namespace lbind
{
LBIND_DEFINE_FUNC(CLabelUI,SetTextStyle)
	pThis->SetTextStyle(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,GetTextStyle)
	return L.lreturn(pThis->GetTextStyle());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,SetTextColor)
	pThis->SetTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,GetTextColor)
	return L.lreturn(pThis->GetTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,SetDisabledTextColor)
	pThis->SetDisabledTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,GetDisabledTextColor)
	return L.lreturn(pThis->GetDisabledTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,SetFont)
	pThis->SetFont(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,GetFont)
	return L.lreturn(pThis->GetFont());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,SetTextPadding)
	pThis->SetTextPadding(toRect(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,GetTextPadding)
	return L.lreturn(toLua(L,pThis->GetTextPadding()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,SetShowHtml)
	pThis->SetShowHtml(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CLabelUI,IsShowHtml)
	return L.lreturn(pThis->IsShowHtml());
LBIND_END_DEFINE_FUNC

}


LBIND_BEGIN_DEFINE_LIB(CLabelUI)
	{"setTextStyle",lbind::SetTextStyle},
	{"textStyle",lbind::GetTextStyle},
	{"setTextColor",lbind::SetTextColor},
	{"textColor",lbind::GetTextColor},
	{"setDisabledTextColor",lbind::SetDisabledTextColor},
	{"disabledTextColor",lbind::GetDisabledTextColor},
	{"setFont",lbind::SetFont},
	{"font",lbind::GetFont},
	{"setTextPadding",lbind::SetTextPadding},
	{"textPadding",lbind::GetTextPadding},
	{"setShowHtml",lbind::SetShowHtml},
	{"isShowHtml",lbind::IsShowHtml},
LBIND_END_DEFINE_LIB





namespace lbind
{

LBIND_DEFINE_FUNC(CButtonUI,SetNormalImage)
	pThis->SetNormalImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,GetNormalImage)
	return L.lreturn(pThis->GetNormalImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,GetHotImage)
	return L.lreturn(pThis->GetHotImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,SetHotImage)
	pThis->SetHotImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CButtonUI,GetPushedImage)
	return L.lreturn(pThis->GetPushedImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,SetPushedImage)
	pThis->SetPushedImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CButtonUI,GetFocusedImage)
	return L.lreturn(pThis->GetFocusedImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,SetFocusedImage)
	pThis->SetFocusedImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,GetDisabledImage)
	return L.lreturn(pThis->GetDisabledImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,SetDisabledImage)
	pThis->SetDisabledImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,SetHotTextColor)
	pThis->SetHotTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,GetHotTextColor)
	return L.lreturn(pThis->GetHotTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,SetPushedTextColor)
	pThis->SetPushedTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,GetPushedTextColor)
	return L.lreturn(pThis->GetPushedTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,SetFocusedTextColor)
	pThis->SetFocusedTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CButtonUI,GetFocusedTextColor)
	return L.lreturn(pThis->GetFocusedTextColor());
LBIND_END_DEFINE_FUNC

}


LBIND_BEGIN_DEFINE_LIB(CButtonUI)
	{"setNormalImage",lbind::SetNormalImage},
	{"normalImage",lbind::GetNormalImage},
	{"hotImage",lbind::GetHotImage},
	{"setHotImage",lbind::SetHotImage},
	{"pushedImage",lbind::GetPushedImage},
	{"setPushedImage",lbind::SetPushedImage},
	{"focusedImage",lbind::GetFocusedImage},
	{"setFocusedImage",lbind::SetFocusedImage},
	{"disabledImage",lbind::GetDisabledImage},
	{"setDisabledImage",lbind::SetDisabledImage},
	{"setHotTextColor",lbind::SetHotTextColor},
	{"hotTextColor",lbind::GetHotTextColor},
	{"setPushedTextColor",lbind::SetPushedTextColor},
	{"pushedTextColor",lbind::GetPushedTextColor},
	{"setFocusedTextColor",lbind::SetFocusedTextColor},
	{"focusedTextColor",lbind::GetFocusedTextColor},
LBIND_END_DEFINE_LIB



namespace lbind
{
LBIND_DEFINE_FUNC(COptionUI,SetSelectedImage)
	pThis->SetSelectedImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,GetSelectedImage)
	return L.lreturn(pThis->GetSelectedImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,SetForeImage)
	pThis->SetForeImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,GetForeImage)
	return L.lreturn(pThis->GetForeImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,SetGroup)
	pThis->SetGroup(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,GetGroup)
	return L.lreturn(pThis->GetGroup());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,SetSelectedTextColor)
	pThis->SetSelectedTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,GetSelectedTextColor)
	return L.lreturn(pThis->GetSelectedTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,Selected)
	pThis->Selected(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(COptionUI,IsSelected)
	return L.lreturn(pThis->IsSelected());
LBIND_END_DEFINE_FUNC

}

LBIND_BEGIN_DEFINE_LIB(COptionUI)
	{"setSelectedImage",lbind::SetSelectedImage},
	{"selectedImage",lbind::GetSelectedImage},
	{"setForeImage",lbind::SetForeImage},
	{"foreImage",lbind::GetForeImage},
	{"setGroup",lbind::SetGroup},
	{"group",lbind::GetGroup},
	{"setSelectedTextColor",lbind::SetSelectedTextColor},
	{"selectedTextColor",lbind::GetSelectedTextColor},
	{"selected",lbind::Selected},
	{"isSelected",lbind::IsSelected},

LBIND_END_DEFINE_LIB




namespace lbind
{
LBIND_DEFINE_FUNC(CTextUI,GetLinkContent)
	return L.lreturn(pThis->GetLinkContent(arg[2].toInt()));
LBIND_END_DEFINE_FUNC

}

LBIND_BEGIN_DEFINE_LIB(CTextUI)
	{"linkContent",lbind::GetLinkContent},
LBIND_END_DEFINE_LIB



namespace lbindprogress
{


LBIND_DEFINE_FUNC(CProgressUI,IsHorizontal)
	return L.lreturn(pThis->IsHorizontal());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,SetHorizontal)
	pThis->SetHorizontal(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,GetMinValue)
	return L.lreturn(pThis->GetMinValue());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,SetMinValue)
	pThis->SetMinValue(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,GetMaxValue)
	return L.lreturn(pThis->GetMaxValue());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,SetMaxValue)
	pThis->SetMaxValue(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,GetValue)
	return L.lreturn(pThis->GetValue());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,SetValue)
	pThis->SetValue(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CProgressUI,GetForeImage)
	return L.lreturn(pThis->GetForeImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CProgressUI,SetForeImage)
	pThis->SetForeImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC
}


LBIND_BEGIN_DEFINE_LIB(CProgressUI)
	{"isHorizontal",lbindprogress::IsHorizontal},
	{"setHorizontal",lbindprogress::SetHorizontal},
	{"minValue",lbindprogress::GetMinValue},
	{"setMinValue",lbindprogress::SetMinValue},
	{"maxValue",lbindprogress::GetMaxValue},
	{"setMaxValue",lbindprogress::SetMaxValue},
	{"value",lbindprogress::GetValue},
	{"setValue",lbindprogress::SetValue},
	{"foreImage",lbindprogress::GetForeImage},
	{"setForeImage",lbindprogress::SetForeImage},
LBIND_END_DEFINE_LIB



namespace lbind
{

LBIND_DEFINE_FUNC(CSliderUI,GetChangeStep)
	return L.lreturn(pThis->GetChangeStep());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,SetChangeStep)
	pThis->SetChangeStep(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CSliderUI,SetThumbSize)
	pThis->SetThumbSize(toSize(arg[2]));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,GetThumbRect)
	L.lreturn(toLua(L,pThis->GetThumbRect()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,GetThumbImage)
	return L.lreturn(pThis->GetThumbImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,SetThumbImage)
	pThis->SetThumbImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,GetThumbHotImage)
	return L.lreturn(pThis->GetThumbHotImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,SetThumbHotImage)
	pThis->SetThumbHotImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,GetThumbPushedImage)
	return L.lreturn(pThis->GetThumbPushedImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CSliderUI,SetThumbPushedImage)
	pThis->SetThumbPushedImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC
}

LBIND_BEGIN_DEFINE_LIB(CSliderUI)
	{"changeStep",lbind::GetChangeStep},
	{"setChangeStep",lbind::SetChangeStep},
	{"setThumbSize",lbind::SetThumbSize},
	{"thumbRect",lbind::GetThumbRect},
	{"thumbImage",lbind::GetThumbImage},
	{"setThumbImage",lbind::SetThumbImage},
	{"thumbHotImage",lbind::GetThumbHotImage},
	{"setThumbHotImage",lbind::SetThumbHotImage},
	{"thumbPushedImage",lbind::GetThumbPushedImage},
	{"setThumbPushedImage",lbind::SetThumbPushedImage},
LBIND_END_DEFINE_LIB


namespace lbindedit
{

LBIND_DEFINE_FUNC(CEditUI,GetMaxChar)
	return L.lreturn(pThis->GetMaxChar());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetMaxChar)
	pThis->SetMaxChar(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,IsReadOnly)
	return L.lreturn(pThis->IsReadOnly());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetReadOnly)
	pThis->SetReadOnly(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,IsPasswordMode)
	return L.lreturn(pThis->IsPasswordMode());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetPasswordMode)
	pThis->SetPasswordMode(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,GetPasswordChar)
	return L.lreturn(pThis->GetPasswordChar());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetPasswordChar)
	pThis->SetPasswordChar(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,GetNormalImage)
	return L.lreturn(pThis->GetNormalImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetNormalImage)
	pThis->SetNormalImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,GetHotImage)
	return L.lreturn(pThis->GetHotImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetHotImage)
	pThis->SetHotImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,GetFocusedImage)
	return L.lreturn(pThis->GetFocusedImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetFocusedImage)
	pThis->SetFocusedImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,GetDisabledImage)
	return L.lreturn(pThis->GetDisabledImage());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetDisabledImage)
	pThis->SetDisabledImage(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,GetNativeEditBkColor)
	return L.lreturn(pThis->GetNativeEditBkColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CEditUI,SetNativeEditBkColor)
	pThis->SetNativeEditBkColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC
}

LBIND_BEGIN_DEFINE_LIB(CEditUI)
	{"maxChar",lbindedit::GetMaxChar},
	{"setMaxChar",lbindedit::SetMaxChar},
	{"isReadOnly",lbindedit::IsReadOnly},
	{"setReadOnly",lbindedit::SetReadOnly},
	{"isPasswordMode",lbindedit::IsPasswordMode},
	{"setPasswordMode",lbindedit::SetPasswordMode},
	{"passwordChar",lbindedit::GetPasswordChar},
	{"normalImage",lbindedit::GetNormalImage},
	{"setNormalImage",lbindedit::SetNormalImage},
	{"hotImage",lbindedit::GetHotImage},
	{"setHotImage",lbindedit::SetHotImage},
	{"focusedImage",lbindedit::GetFocusedImage},
	{"setFocusedImage",lbindedit::SetFocusedImage},
	{"disabledImage",lbindedit::GetDisabledImage},
	{"setDisabledImage",lbindedit::SetDisabledImage},
	{"nativeEditBkColor",lbindedit::GetNativeEditBkColor},
	{"setNativeEditBkColor",lbindedit::SetNativeEditBkColor},
LBIND_END_DEFINE_LIB

namespace lbind
{

LBIND_DEFINE_FUNC(CScrollBarUI,IsHorizontal)
	return L.lreturn(pThis->IsHorizontal());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CScrollBarUI,SetHorizontal)
	pThis->SetHorizontal(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CScrollBarUI,GetScrollRange)
	return L.lreturn(pThis->GetScrollRange());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CScrollBarUI,SetScrollRange)
	pThis->SetScrollRange(arg[2].toInt());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CScrollBarUI,GetScrollPos)
	return L.lreturn(pThis->GetScrollPos());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CScrollBarUI,SetScrollPos)
	pThis->SetScrollPos(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CScrollBarUI,GetLineSize)
	return L.lreturn(pThis->GetLineSize());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CScrollBarUI,SetLineSize)
	pThis->SetLineSize(arg[2].toInt());
LBIND_END_DEFINE_FUNC

}



LBIND_BEGIN_DEFINE_LIB(CScrollBarUI)
	{"isHorizontal",lbind::IsHorizontal},
	{"setHorizontal",lbind::SetHorizontal},
	{"scrollRange",lbind::GetScrollRange},
	{"setScrollRange",lbind::SetScrollRange},
	{"scrollPos",lbind::GetScrollPos},
	{"setScrollPos",lbind::SetScrollPos},
	{"lineSize",lbind::GetLineSize},
	{"setLineSize",lbind::SetLineSize},
LBIND_END_DEFINE_LIB