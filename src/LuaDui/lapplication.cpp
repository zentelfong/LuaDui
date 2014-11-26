#include "StdAfx.h"
using namespace DuiLib;

namespace lbind
{
LBIND_DEFINE_STATIC_FUNC(CApplicationUI,SharedInstance)
	return L.lreturn(CApplicationUI::SharedInstance()->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CApplicationUI,GetInstance)
	return L.lreturn(((lua_Integer)bindPtr->GetInstance()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetInstancePath)
	return L.lreturn(bindPtr->GetInstancePath());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetCurrentPath)
	return L.lreturn(bindPtr->GetCurrentPath());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetResourcePath)
	return L.lreturn(bindPtr->GetResourcePath());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetResourceZip)
	return L.lreturn(bindPtr->GetResourceZip());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,IsCachedResourceZip)
	return L.lreturn(bindPtr->IsCachedResourceZip());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetCurrentPath)
	bindPtr->SetCurrentPath(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetResourcePath)
	bindPtr->SetResourcePath(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetResourceZip)
	bindPtr->SetResourceZip(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetHSL)
	short h,s,l;
	bindPtr->GetHSL(&h,&s,&l);
	return L.lreturn(h,s,l);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetHSL)
	bindPtr->SetHSL(arg[2].toBool(),arg[3].toInt(),arg[4].toInt(),arg[5].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,ReloadSkin)
	bindPtr->ReloadSkin();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,LoadPlugin)
	bindPtr->LoadPlugin(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC
}

LBIND_BEGIN_DEFINE_LIB(CApplicationUI)
{"sharedInstance",lbind::SharedInstance},
{"getInstance",lbind::GetInstance},
{"instancePath",lbind::GetInstancePath},
{"currentPath",lbind::GetCurrentPath},
{"resourcePath",lbind::GetResourcePath},
{"resourceZip",lbind::GetResourceZip},

{"isCachedResourceZip",lbind::IsCachedResourceZip},
{"setCurrentPath",lbind::SetCurrentPath},

{"setResourcePath",lbind::SetResourcePath},
{"setResourceZip",lbind::SetResourceZip},
{"HSL",lbind::GetHSL},
{"setHSL",lbind::SetHSL},
{"reloadSkin",lbind::ReloadSkin},
{"loadPlugin",lbind::LoadPlugin},

LBIND_END_DEFINE_LIB

















