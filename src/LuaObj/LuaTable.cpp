#include "LuaTable.h"
#include "LuaObjectImpl.h"


LuaTable::LuaTable(LuaState* L)
	:LuaObject(L)
{
	
}

LuaTable::LuaTable(LuaObjectImpl* impl)
	:LuaObject(impl)
{
	
}

LuaTable::LuaTable(const LuaObject& rfs)
	:LuaObject(rfs)
{
}

LuaTable::LuaTable(const LuaTable& rfs)
	:LuaObject(rfs)
{
}


bool LuaTable::isValid()
{
	return getType()==LUA_TTABLE;
}

LuaObject LuaTable::getTable(const char* key)
{
	assert(isValid());
	return LuaObjectImpl::createGetTable(m_ptr->getCppLuaState(),m_ptr,key);
}

LuaObject LuaTable::getTable(lua_Integer key)
{
	assert(isValid());
	return LuaObjectImpl::createGetTable(m_ptr->getCppLuaState(),m_ptr,key);
}

LuaObject LuaTable::operator[](const char* key)
{
	assert(isValid());
	return LuaObjectImpl::createGetTable(m_ptr->getCppLuaState(),m_ptr,key);
}

LuaObject LuaTable::operator[](lua_Integer idx)
{
	assert(isValid());
	return LuaObjectImpl::createGetTable(m_ptr->getCppLuaState(),m_ptr,idx);
}

bool LuaTable::setTable(const char* key,LuaObject val)
{
	if(isValid())
	{
		lua_State* L=m_ptr->getLuaState();
		lua_pushstring(L,key);//key
		if(val.isNone())
			lua_pushnil(L);
		else
			lua_pushvalue(L,val.getIndex());//value
		lua_settable(L,getIndex());
		return true;
	}
	return false;
}

bool LuaTable::setTable(lua_Integer key,LuaObject val)
{
	if(isValid())
	{
		lua_State* L=m_ptr->getLuaState();
		lua_pushinteger(L,key);//key
		if(val.isNone())
			lua_pushnil(L);
		else
			lua_pushvalue(L,val.getIndex());//value
		lua_settable(L,getIndex());
		return true;
	}
	return false;
}