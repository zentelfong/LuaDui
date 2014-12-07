#include "StdAfx.h"
#include "lutil.h"

using namespace DuiLib;

namespace lbindrichedit
{
using namespace lbind;

typedef struct FontFormat
{
	FontFormat():underline(false),color(0),font(_T("")),size(9),bold(false),italic(false)
	{
	}
	bool	underline;
	DWORD	color;
	CStdString font;
	UINT	size;
	bool    bold;
	bool	italic;
}FontFormat;

//从lua表中读取字体格式
bool textFormatFromLua(LuaTable ltab,CHARFORMAT2 & format)
{
	if (!ltab.isValid())
	{
		return false;
	}
    ZeroMemory(&format, sizeof(CHARFORMAT2));
    format.cbSize = sizeof(format);
    format.dwReserved = 0;

	if(!ltab.isTable())
		return false;
	DWORD mask=0;//指定有效值
	DWORD efect=0;


	LuaObject lvalue=ltab.getTable("bold");
	if(!lvalue.isNil())//是否粗体
	{
		mask|=CFM_BOLD;
		if(lvalue.toBool())
			efect|=CFE_BOLD;
	}

	lvalue=ltab.getTable("italic");
	if(!lvalue.isNil())//是否斜体
	{
		mask|=CFM_ITALIC;
		if(lvalue.toBool())
			efect|=CFE_ITALIC;
	}


	lvalue=ltab.getTable("link");
	if(!lvalue.isNil())//是否链接
	{
		mask|=CFM_LINK;
		if(lvalue.toBool())
			efect|=CFE_LINK;
	}


	lvalue=ltab.getTable("underline");
	if(!lvalue.isNil())
	{
		mask|=CFM_UNDERLINE;
		if(lvalue.toBool())
			efect|=CFE_UNDERLINE;
	}

	lvalue=ltab.getTable("size");
	if(lvalue.isNumber())
	{
		mask|=CFM_SIZE;
		HDC hDC = ::GetDC(NULL);
		format.yHeight=15 * MulDiv(lvalue.toInt(), GetDeviceCaps(hDC, LOGPIXELSY), 72);  
		::ReleaseDC(NULL, hDC);
	}

	lvalue=ltab.getTable("offset");
	if(lvalue.isNumber())
	{
		mask|=CFM_OFFSET;
		format.yOffset=lvalue.toInt();
	}

	lvalue=ltab.getTable("bkcolor");
	if(lvalue.isNumber())
	{
		mask|=CFM_BACKCOLOR;
		format.crBackColor=lvalue.toInt();
	}

	lvalue=ltab.getTable("color");
	if(lvalue.isNumber())
	{
		mask|=CFM_COLOR;
		format.crTextColor=lvalue.toInt();
	}

	lvalue=ltab.getTable("font");
	if(lvalue.isString())
	{
		mask|=CFM_FACE;
		_tcscpy(format.szFaceName,CStdString(lvalue.toString()));//小于32个字符
	}

	lvalue=ltab.getTable("weight");
	if(lvalue.isNumber())
	{
		mask|=CFM_WEIGHT;
		format.wWeight=lvalue.toInt();
	}


	lvalue=ltab.getTable("spacing");
	if(lvalue.isNumber())
	{
		mask|=CFM_SPACING;
		format.sSpacing=lvalue.toInt();
	}


	format.dwMask=mask;
	format.dwEffects=efect;
	return true;
}

bool textFormatFromLua(LuaTable ltab,FontFormat & format)
{
	if (!ltab.isValid())
	{
		return false;
	}
	LuaObject value=ltab.getTable("bold");
	if(value.toBool())//是否粗体
	{
		format.bold=true;
	}
	else
		format.bold=false;

	value=ltab.getTable("italic");
	if(value.toBool())//是否斜体
	{
		format.italic=true;
	}
	else
		format.italic=false;

	value=ltab.getTable("underline");
	if(value.toBool())//是否斜体
	{
		format.underline=true;
	}
	else
		format.underline=false;
	
	value=ltab.getTable("font");
	if(value.isString())//是否斜体
	{
		format.font=value.toString();
	}	

	value=ltab.getTable("color");
	if(value.isNumber())//是否斜体
	{
		format.color=value.toInt();
	}

	value=ltab.getTable("size");
	if(value.isNumber())//是否斜体
	{
		format.size=value.toInt();
	}

	return true;
}


LBIND_DEFINE_FUNC(CRichEditUI,SetWantTab)
	pThis->SetWantTab(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,IsWantTab)
	return L.lreturn(pThis->IsWantTab());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CRichEditUI,SetWantReturn)
	pThis->SetWantReturn(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,IsWantReturn)
	return L.lreturn(pThis->IsWantReturn());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetWantCtrlReturn)
	pThis->SetWantCtrlReturn(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,IsWantCtrlReturn)
	return L.lreturn(pThis->IsWantCtrlReturn());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetRich)
	pThis->SetRich(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,IsRich)
	return L.lreturn(pThis->IsRich());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CRichEditUI,SetReadOnly)
	pThis->SetReadOnly(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,IsReadOnly)
	return L.lreturn(pThis->IsReadOnly());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CRichEditUI,SetWordWrap)
	pThis->SetWordWrap(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetWordWrap)
	return L.lreturn(pThis->GetWordWrap());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetFont)
	pThis->SetFont(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetFont)
	return L.lreturn(pThis->GetFont());
LBIND_END_DEFINE_FUNC



LBIND_DEFINE_FUNC(CRichEditUI,SetFontFormat)
	FontFormat format;
	if (textFormatFromLua(arg[2],format))
	{
		pThis->SetFont(format.font,format.size,format.bold,format.underline,format.italic);
	}
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetWinStyle)
	pThis->SetWinStyle(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetWinStyle)
	return L.lreturn(pThis->GetWinStyle());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetTextColor)
	pThis->SetTextColor(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetTextColor)
	return L.lreturn(pThis->GetTextColor());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetLimitText)
	pThis->SetLimitText(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetLimitText)
	return L.lreturn(pThis->GetLimitText());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CRichEditUI,GetTextLength)
	return L.lreturn(pThis->GetTextLength());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetText)
	return L.lreturn(pThis->GetText().GetString());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetText)
	pThis->SetText(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetModify)
	pThis->SetModify(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetModify)
	return L.lreturn(pThis->GetModify());
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CRichEditUI,GetSel)
	CHARRANGE range;
	pThis->GetSel(range);
	return L.lreturn(range.cpMin,range.cpMax);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetSel)
	pThis->SetSel(arg[2].toInt(),arg[3].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,ReplaceSel)
	pThis->ReplaceSel(CStdString(arg[2].toString()),arg[3].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetSelText)
	return L.lreturn(pThis->GetSelText().GetString());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetSelAll)
	pThis->SetSelAll();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetSelNone)
	pThis->SetSelNone();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetSelectionType)
	return L.lreturn(pThis->GetSelectionType());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetZoom)
	int nNum,nDen;
	pThis->GetZoom(nNum,nDen);
	return L.lreturn(nNum,nDen);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetZoom)
	pThis->SetZoom(arg[2].toInt(),arg[3].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetZoomOff)
	pThis->SetZoomOff();
LBIND_END_DEFINE_FUNC




LBIND_DEFINE_FUNC(CRichEditUI,SetAutoURLDetect)
	pThis->SetAutoURLDetect(arg[2].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetAutoURLDetect)
	return L.lreturn(pThis->GetAutoURLDetect());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetEventMask)
	pThis->SetEventMask(arg[2].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetEventMask)
	return L.lreturn(pThis->GetEventMask());
LBIND_END_DEFINE_FUNC



LBIND_DEFINE_FUNC(CRichEditUI,HideSelection)
	pThis->HideSelection(arg[2].toBool(),arg[3].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,ScrollCaret)
	pThis->ScrollCaret();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,InsertText)
	pThis->InsertText(arg[2].toInt(),CStdString(arg[3].toString()),arg[4].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,AppendText)
	pThis->AppendText(CStdString(arg[2].toString()),arg[3].toBool());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,Redo)
	pThis->Redo();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,Undo)
	pThis->Undo();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,Clear)
	pThis->Clear();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,Copy)
	pThis->Copy();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,Cut)
	pThis->Cut();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,Paste)
	pThis->Paste();
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CRichEditUI,GetLineCount)
	return L.lreturn(pThis->GetLineCount());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetLine)
	return L.lreturn(pThis->GetLine(arg[2].toInt(),arg[3].toInt()));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CRichEditUI,LineIndex)
	return L.lreturn(pThis->LineIndex(arg[2].toInt()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,LineLength)
	return L.lreturn(pThis->LineLength(arg[2].toInt()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,LineScroll)
	return L.lreturn(pThis->LineScroll(arg[2].toInt(),arg[3].toInt()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,GetCharPos)
	return L.lreturn(toLua(L,pThis->GetCharPos(arg[2].toInt())));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,LineFromChar)
	return L.lreturn(pThis->LineFromChar(arg[2].toInt()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,PosFromChar)
	return L.lreturn(toLua(L,pThis->PosFromChar(arg[2].toInt())));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,CharFromPos)
	return L.lreturn(pThis->CharFromPos(toPoint(arg[2])));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,EmptyUndoBuffer)
	pThis->EmptyUndoBuffer();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CRichEditUI,SetUndoLimit)
	return L.lreturn(pThis->SetUndoLimit(arg[2].toInt()));
LBIND_END_DEFINE_FUNC



}



LBIND_BEGIN_DEFINE_LIB(CRichEditUI)
	{"setWantTab",lbindrichedit::SetWantTab},
	{"isWantTab",lbindrichedit::IsWantTab},
	{"setWantReturn",lbindrichedit::SetWantReturn},
	{"isWantReturn",lbindrichedit::IsWantReturn},
	{"setWantCtrlReturn",lbindrichedit::SetWantCtrlReturn},
	{"isWantCtrlReturn",lbindrichedit::IsWantCtrlReturn},
	{"setRich",lbindrichedit::SetRich},
	{"isRich",lbindrichedit::IsRich},
	{"setReadOnly",lbindrichedit::SetReadOnly},
	{"isReadOnly",lbindrichedit::IsReadOnly},
	{"setWordWrap",lbindrichedit::SetWordWrap},
	{"wordWrap",lbindrichedit::GetWordWrap},
	{"setFont",lbindrichedit::SetFont},
	{"font",lbindrichedit::GetFont},
	{"setFontFormat",lbindrichedit::SetFontFormat},
	{"setWinStyle",lbindrichedit::SetWinStyle},
	{"winStyle",lbindrichedit::GetWinStyle},
	{"setTextColor",lbindrichedit::SetTextColor},
	{"textColor",lbindrichedit::GetTextColor},
	{"setLimitText",lbindrichedit::SetLimitText},
	{"limitText",lbindrichedit::GetLimitText},
	{"textLength",lbindrichedit::GetTextLength},
	{"text",lbindrichedit::GetText},
	{"setText",lbindrichedit::SetText},
	{"setModify",lbindrichedit::SetModify},
	{"modify",lbindrichedit::GetModify},

	{"sel",lbindrichedit::GetSel},
	{"replaceSel",lbindrichedit::ReplaceSel},
	{"selText",lbindrichedit::GetSelText},
	{"setSelAll",lbindrichedit::SetSelAll},
	{"setSelNone",lbindrichedit::SetSelNone},
	{"selectionType",lbindrichedit::GetSelectionType},
	{"zoom",lbindrichedit::GetZoom},
	{"setZoom",lbindrichedit::SetZoom},
	{"setZoomOff",lbindrichedit::SetZoomOff},

	{"setAutoURLDetect",lbindrichedit::SetAutoURLDetect},
	{"autoURLDetect",lbindrichedit::GetAutoURLDetect},
	{"setEventMask",lbindrichedit::SetEventMask},
	{"eventMask",lbindrichedit::GetEventMask},
	{"hideSelection",lbindrichedit::HideSelection},
	{"scrollCaret",lbindrichedit::ScrollCaret},
	{"insertText",lbindrichedit::InsertText},
	{"appendText",lbindrichedit::AppendText},

	{"redo",lbindrichedit::Redo},
	{"undo",lbindrichedit::Undo},
	{"clear",lbindrichedit::Clear},
	{"copy",lbindrichedit::Copy},
	{"cut",lbindrichedit::Cut},
	{"paste",lbindrichedit::Paste},
	{"lineCount",lbindrichedit::GetLineCount},
	{"line",lbindrichedit::GetLine},
	{"lineIndex",lbindrichedit::LineIndex},
	{"lineLength",lbindrichedit::LineLength},

	{"lineScroll",lbindrichedit::LineScroll},
	{"charPos",lbindrichedit::GetCharPos},
	{"lineFromChar",lbindrichedit::LineFromChar},
	{"posFromChar",lbindrichedit::PosFromChar},
	{"charFromPos",lbindrichedit::CharFromPos},
	{"emptyUndoBuffer",lbindrichedit::EmptyUndoBuffer},
	{"setUndoLimit",lbindrichedit::SetUndoLimit},
LBIND_END_DEFINE_LIB