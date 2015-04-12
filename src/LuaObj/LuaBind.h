#include "LuaEngine.h"
#include "LuaObject.h"


//基类需要实现以下几个函数
#define LBIND_BASE_CLASS_DEFINE(Class)\
private:\
	static const LuaReg _lualib[];\
protected:\
	static void _lbindBaseRegisterLib(const char* className,const char* baseName,const LuaReg lib[])\
	{\
		LuaEngine* L=LuaManager::instance()->current();\
		LuaTable luaClass=L->newLib((LuaReg*)lib);\
		LuaTable envTable=L->getGlobal("UI");\
		luaClass.setMetatable(envTable.getTable(baseName));\
		luaClass.setTable("__index",luaClass);\
		envTable.setTable(className,luaClass);\
	}\
	static Class* _lbindBaseLuaToC(LuaObject obj)\
	{\
		typedef void* data;\
		if(obj.getType()==LUA_TUSERDATA)\
		{\
			Class* ptr=static_cast<Class*>(*((data*)obj.toData()));\
			return ptr;\
		}\
		else\
			return NULL;\
	}\
	virtual LuaObject _lbindBaseCToLua(LuaState* L,Class* ptr,const char* className)\
	{\
		typedef void* data;\
		if (!ptr)\
		{\
			return L->newNil();\
		}\
		LuaObject obj=L->newData(&ptr,sizeof(ptr));\
		LuaTable envTable=L->getGlobal("UI");\
		obj.setMetatable(envTable.getTable(className));\
		return obj;\
	}\
public:\
	static void _lbindRegisterLib(LuaState* L)\
	{\
		LuaTable llib=L->newLib((LuaReg*)_lualib);\
		llib.setTable("__index",llib);\
		LuaTable envTable=L->getGlobal("UI");\
		envTable.setTable(#Class,llib);\
	}\
	static Class* _lbindLuaToC(LuaObject obj)\
	{\
		return static_cast<Class*>(_lbindBaseLuaToC(obj));\
	}\
	virtual LuaObject _lbindCToLua(LuaState* L)\
	{\
		return _lbindBaseCToLua(L,this,#Class);\
	}




#define LBIND_CLASS_DEFINE(Class,BaseClass)\
private:\
static const LuaReg _lualib[];\
public:\
	static void _lbindRegisterLib(LuaState* L)\
	{\
		_lbindBaseRegisterLib(#Class,#BaseClass,_lualib);\
	}\
	static Class* _lbindLuaToC(LuaObject obj)\
	{\
		return static_cast<Class*>(_lbindBaseLuaToC(obj));\
	}\
	virtual LuaObject _lbindCToLua(LuaState* L)\
	{\
		return _lbindBaseCToLua(L,this,#Class);\
	}

//主函数调用注册库
#define LBIND_REGISTER_CLASS(Class,L) Class::_lbindRegisterLib(L)


//定义lib
#define LBIND_BEGIN_DEFINE_LIB(Class)\
	const LuaReg Class::_lualib[]={


#define LBIND_END_DEFINE_LIB\
 {NULL,NULL}\
};

#define LBIND_FUNC_MAP(name,func)\
	{name,func},


//定义函数
#define LBIND_DEFINE_FUNC(Class,Func)\
	int Func(LuaState& L,LuaTable &arg)\
{\
	Class* pThis=Class::_lbindLuaToC(arg[1]);\
	if(!pThis)\
	{\
		L.error("lbind arg1 is not a object,file %s,line %d",__FILE__,__LINE__);\
		return 0;\
	}



#define LBIND_END_DEFINE_FUNC return 0;}

//定义静态函数没有bindPtr指针
#define LBIND_DEFINE_STATIC_FUNC(Class,Func)\
	int Func(LuaState& L,LuaTable &arg)\
{


///////////////////////////////////////////////////////////////////
#define CHECK_ARG_NUM(idx) \
	if(arg[idx].getType()!=LUA_TNUMBER)\
	{\
		L.error("file %s,function %s,arg %d need a number",__FILE__,__FUNCTION__,idx);\
		return 0;\
	}

#define CHECK_ARG_STRING(idx)\
	if(arg[idx].getType()!=LUA_TSTRING)\
	{\
		L.error("file %s,function %s,arg %d need a string",__FILE__,__FUNCTION__,idx);\
		return 0;\
	}

#define CHECK_ARG_TABLE(idx)\
	if(arg[idx].getType()!=LUA_TTABLE)\
	{\
		L.error("file %s,function %s,arg %d need a table",__FILE__,__FUNCTION__,idx);\
		return 0;\
	}

#define CHECK_ARG_UDATA(idx)\
	if(arg[idx].getType()!=LUA_TUSERDATA)\
	{\
		L.error("file %s,function %s,arg %d need a user data",__FILE__,__FUNCTION__,idx);\
		return 0;\
	}

#define CHECK_ARG_PTR(idx)\
	if(arg[idx].getType()!=LUA_TLIGHTUSERDATA)\
	{\
		L.error("file %s,function %s,arg %d need a light user data",__FILE__,__FUNCTION__,idx);\
		return 0;\
	}

#define CHECK_ARG_FUNC(idx)\
	if(arg[idx].getType()!=LUA_TFUNCTION)\
	{\
		L.error("file %s,function %s,arg %d need a function",__FILE__,__FUNCTION__,idx);\
		return 0;\
	}

#define CHECK_ARG_BOOL(idx)\
	if(arg[idx].getType()!=LUA_TBOOLEAN)\
	{\
		L.error("file %s,function %s,arg %d need a bool",__FILE__,__FUNCTION__,idx);\
		return 0;\
	}




/*

//lua对象的使用如下：

class Base
{
	LBIND_BASE_CLASS_DEFINE(Base);//实现定义
};


class Test:public Base
{
	LBIND_CLASS_DEFINE(Test,Base);

}


LBIND_DEFINE_FUNC(Test,test)

	
}

LBIND_DEFINE_FUNC(Test,test2)


}

LBIND_DEFINE_FUNC(Test,test3)


}


LBIND_BEGIN_DEFINE_LIB(Test)


LBIND_END_DEFINE_LIB


*/