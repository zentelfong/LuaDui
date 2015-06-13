#pragma once
#include "LuaCommon.h"
#include "LuaObject.h"
#include "LuaTable.h"
#include "LuaException.h"
#include "LuaStack.h"


class LuaObjectStack
{
public:
	void push(LuaObjectImpl* impl);
	void pop(LuaObjectImpl* impl);
private:
	std::vector<LuaObjectImpl*> m_data;
};


class LuaState
{
public:
	LuaState(lua_State* L);
	~LuaState(void);

	LuaObject getGlobal(const char* name);
	void setGlobal(const char* name,LuaObject obj);

	LuaObject getRegistery(const char* key);
	LuaObject getRegistery(void* key);
	void setRegistry(const char* key,const LuaObject obj);
	void setRegistry(const void *key,const LuaObject obj);

	LuaObject newNil();
	LuaObject newNumber(lua_Number);
	LuaObject newInt(lua_Integer);

	LuaObject newString(const char*,int len=-1);

	LuaObject newString(const wchar_t*,int len=-1);

	LuaObject newPtr(void* p);//light userdata
	LuaObject newData(void* p,size_t sz);//userdata

	LuaObject newBool(bool);
	LuaObject newFunction(lua_CFunction);

	LuaObject newFunction(LuaCFunction);
	LuaTable newLib(const LuaReg lib[]);
	
	void openLib(const char* name,lua_CFunction openfunc);

	//do string
	LuaObject  doFile(const char *fileName);
	LuaObject  doString(const char *str);


	LuaObject  require(const char *file);

	virtual void error(const char* errorMsg,...);

	//创建多个参数
	LuaTable newTable();


	lua_State* getLuaState(){return m_ls;}

	int getTop(){return lua_gettop(m_ls);}

	template<class T1>
	int lreturn(T1 t1)
	{
		assert(m_type==LST_STACK);
		StackOps::Push(m_ls,t1);
		return 1;
	}

	template<class T1,class T2>
	int lreturn(T1 t1,T2 t2)
	{
		assert(m_type==LST_STACK);
		StackOps::Push(m_ls,t1);
		StackOps::Push(m_ls,t2);
		return 2;
	}

	template<class T1,class T2,class T3>
	int lreturn(T1 t1,T2 t2,T3 t3)
	{
		assert(m_type==LST_STACK);
		StackOps::Push(m_ls,t1);
		StackOps::Push(m_ls,t2);
		StackOps::Push(m_ls,t3);
		return 3;
	}

	template<class T1,class T2,class T3,class T4>
	int lreturn(T1 t1,T2 t2,T3 t3,T4 t4)
	{
		assert(m_type==LST_STACK);
		StackOps::Push(m_ls,t1);
		StackOps::Push(m_ls,t2);
		StackOps::Push(m_ls,t3);
		StackOps::Push(m_ls,t4);
		return 4;
	}

	template<class T1,class T2,class T3,class T4,class T5>
	int lreturn(T1 t1,T2 t2,T3 t3,T4 t4,T5 t5)
	{
		assert(m_type==LST_STACK);
		StackOps::Push(m_ls,t1);
		StackOps::Push(m_ls,t2);
		StackOps::Push(m_ls,t3);
		StackOps::Push(m_ls,t4);
		StackOps::Push(m_ls,t5);
		return 5;
	}

	LuaObjectStack* getStack(){return &m_stack;}

	void enumStack();
protected:
	enum LuaStateType{
		LST_STACK,
		LST_OWNER
	};
	LuaStateType m_type;
	lua_State* m_ls;
	LuaObjectStack m_stack;
};

