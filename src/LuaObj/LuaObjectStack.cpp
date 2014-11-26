#include "LuaObjectStack.h"
#include "LuaTable.h"
#include "LuaState.h"


int LuaObjectData::release()
{
	int count =--m_ref;
	if (!count) 
	{
		m_lstack->pop(this);
	}
	return count;
}

lua_State* LuaObjectData::getLuaState()const
{
	return m_lstack->getLuaState();
}


int LuaObjectStack::callDelegate(lua_State* L)
{
	LuaCFunction func =*((LuaCFunction*)(lua_touserdata(L, lua_upvalueindex(1))));
	LuaState LS(L);
	LuaTable args=LS.newTable();//入口参数

	for (int i=1;i<=lua_gettop(L);++i)
	{
		lua_pushnumber(L,i);
		lua_pushvalue(L,i);
		lua_settable(L,args.getIndex());
	}
	LuaObject rtn=func(LS,args);
	if(rtn.isNone())
	{
		return 0;
	}
	else
	{
		lua_pushvalue(L,rtn.getIndex());
		return 1;
	}
}