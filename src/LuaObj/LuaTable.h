#pragma once
#include "LuaCommon.h"
#include "LuaObject.h"
#include "LuaStack.h"

class LuaTable:public LuaObject
{
public:
	LuaTable(LuaState* L);
	LuaTable(LuaObjectImpl* impl);
	LuaTable(const LuaObject& rfs);
	LuaTable(const LuaTable& rfs);

	//判断是否是lua表
	bool isValid();

	//lua表操作
	LuaObject getTable(const char* key);
	LuaObject getTable(lua_Integer idx);

	LuaObject operator[](const char* key);
	LuaObject operator[](lua_Integer idx);


	bool setTable(const char* key,LuaObject val);
	bool setTable(lua_Integer key,LuaObject val);

	inline size_t count()const{return objLen();}

	template<class T>
	bool setTable(const char* key,T val)
	{
		if(isValid())
		{
			lua_State* L=getLuaState();
			lua_pushstring(L,key);//key
			StackOps::Push(getLuaState(),val);
			lua_settable(L,getIndex());
			return true;
		}
		return false;
	}

	template<class T>
	bool setTable(lua_Integer key,T val)
	{
		if(isValid())
		{
			lua_State* L=getLuaState();
			lua_pushinteger(L,key);//key
			StackOps::Push(getLuaState(),val);
			lua_settable(L,getIndex());
			return true;
		}
		return false;	
	}
};

