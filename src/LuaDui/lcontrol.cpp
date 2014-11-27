#include "StdAfx.h"
using namespace DuiLib;

namespace lbind
{
 //   virtual const RECT& GetPos() const;
 //   virtual void SetPos(RECT rc);
 //   virtual int GetWidth() const;
 //   virtual int GetHeight() const;
 //   virtual int GetX() const;
 //   virtual int GetY() const;
 //   virtual RECT GetPadding() const;
 //   virtual void SetPadding(RECT rcPadding); // 设置外边距，由上层窗口绘制
 //   virtual SIZE GetFixedXY() const;         // 实际大小位置使用GetPos获取，这里得到的是预设的参考值
 //   virtual void SetFixedXY(SIZE szXY);      // 仅float为true时有效
 //   virtual int GetFixedWidth() const;       // 实际大小位置使用GetPos获取，这里得到的是预设的参考值
 //   virtual void SetFixedWidth(int cx);      // 预设的参考值
 //   virtual int GetFixedHeight() const;      // 实际大小位置使用GetPos获取，这里得到的是预设的参考值
 //   virtual void SetFixedHeight(int cy);     // 预设的参考值
 //   virtual int GetMinWidth() const;
 //   virtual void SetMinWidth(int cx);
 //   virtual int GetMaxWidth() const;
 //   virtual void SetMaxWidth(int cx);
 //   virtual int GetMinHeight() const;
 //   virtual void SetMinHeight(int cy);
 //   virtual int GetMaxHeight() const;
 //   virtual void SetMaxHeight(int cy);
 //   virtual void SetRelativePos(SIZE szMove,SIZE szZoom);
 //   virtual void SetRelativeParentSize(SIZE sz);
 //   virtual TRelativePosUI GetRelativePos() const;
 //   virtual bool IsRelativePos() const;

LBIND_DEFINE_FUNC(CControlUI,GetPos)
	RECT rc=bindPtr->GetPos();
	return L.lreturn(rc.left,rc.top,rc.right,rc.bottom);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,SetPos)
	RECT rc={0};
	rc.left=arg[2].toInt();
	rc.top=arg[3].toInt();
	rc.right=arg[4].toInt();
	rc.bottom=arg[5].toInt();
	bindPtr->SetPos(rc);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetWidth)
	return L.lreturn(bindPtr->GetWidth());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetHeight)
	return L.lreturn(bindPtr->GetHeight());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetX)
	return L.lreturn(bindPtr->GetX());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CControlUI,GetY)
	return L.lreturn(bindPtr->GetY());
LBIND_END_DEFINE_FUNC




}

LBIND_BEGIN_DEFINE_LIB(CControlUI)

LBIND_END_DEFINE_LIB

















