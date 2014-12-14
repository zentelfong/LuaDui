#include "StdAfx.h"
using namespace DuiLib;


namespace lbind
{

LBIND_DEFINE_FUNC(CDialogBuilder,LoadFile)
	return L.lreturn(pThis->LoadFile(CStdString(arg[2].toString())));
LBIND_END_DEFINE_FUNC

LBIND_DEFINE_FUNC(CDialogBuilder,LoadString)
	return L.lreturn(pThis->LoadString(arg[2].toString()));
LBIND_END_DEFINE_FUNC


class LuaDialogBuilderCallback:public IDialogBuilderCallback
{
public:
	LuaDialogBuilderCallback(LuaFunction func)
		:m_callLua(func)
	{
	}

	CControlUI* CreateControl(LPCTSTR pstrClass)
	{
		CControlUI* ctl=NULL;
		try{
			LuaObject lctl=m_callLua(pstrClass);
			ctl=CControlUI::_lbindLuaToC(lctl);
		}
		catch(LuaException e)
		{
			LOGE("call lua error:"<<e.what());
		}
		return ctl;
	}
private:
	LuaFunction m_callLua;
};

//构造控件parent,callback,返回构造成功的控件
LBIND_DEFINE_FUNC(CDialogBuilder,BuildControl)
	if (pThis->GetManager() && pThis->GetManager()->CheckAvalible())
	{
		CControlUI* buildCtl=NULL;
		CControlUI* parent=CControlUI::_lbindLuaToC(arg[2]);
		LuaFunction lcallback=arg[3];
		if (lcallback.isValid())
		{
			LuaDialogBuilderCallback callback(lcallback);
			buildCtl=pThis->Create(&callback,parent);
		}
		else
		{
			buildCtl=pThis->Create(NULL,parent);
		}

		if (buildCtl)
		{
			return L.lreturn(buildCtl->_lbindCToLua(&L));
		}
	}
LBIND_END_DEFINE_FUNC


LBIND_DEFINE_FUNC(CDialogBuilder,Delete)
	typedef CDialogBuilder* data_t;
	delete pThis;
	data_t* builder=(data_t*)arg[1].toData();
	*builder=NULL;
LBIND_END_DEFINE_FUNC

}



LBIND_BEGIN_DEFINE_LIB(CDialogBuilder)
	{"loadFile",lbind::LoadFile},
	{"loadString",lbind::LoadString},
	{"buildControl",lbind::BuildControl},
	{"delete",lbind::Delete},
	{"__gc",lbind::Delete},
LBIND_END_DEFINE_LIB