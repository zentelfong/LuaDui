#include "StdAfx.h"
using namespace DuiLib;

namespace lbind
{
LBIND_DEFINE_STATIC_FUNC(CApplicationUI,SharedInstance)
	return L.lreturn(CApplicationUI::SharedInstance()->_lbindCToLua(&L));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_STATIC_FUNC(CApplicationUI,Quit)
	if (arg.count()>1)
		PostQuitMessage(arg[2].toInt());
	else
		PostQuitMessage(arg[1].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetInstance)
	return L.lreturn(((lua_Integer)pThis->GetInstance()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetInstancePath)
	return L.lreturn(pThis->GetInstancePath());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetCurrentPath)
	return L.lreturn(pThis->GetCurrentPath());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetResourcePath)
	return L.lreturn(pThis->GetResourcePath());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetResourceZip)
	return L.lreturn(pThis->GetResourceZip());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,IsCachedResourceZip)
	return L.lreturn(pThis->IsCachedResourceZip());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetCurrentPath)
	pThis->SetCurrentPath(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetResourcePath)
	pThis->SetResourcePath(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetResourceZip)
	pThis->SetResourceZip(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,GetHSL)
	short h,s,l;
	pThis->GetHSL(&h,&s,&l);
	return L.lreturn(h,s,l);
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,SetHSL)
	pThis->SetHSL(arg[2].toBool(),arg[3].toInt(),arg[4].toInt(),arg[5].toInt());
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,ReloadSkin)
	pThis->ReloadSkin();
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CApplicationUI,LoadPlugin)
	pThis->LoadPlugin(CStdString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


}

LBIND_BEGIN_DEFINE_LIB(CApplicationUI)
{"quit",lbind::Quit},
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

















