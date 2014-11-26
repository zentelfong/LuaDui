#include "LuaObject.h"
#include "LuaTable.h"
#include "LuaObjectImpl.h"

LuaObject luaNil((LuaObjectImpl*)NULL);


LuaObject::LuaObject(LuaState* L)
{
	m_ptr=LuaObjectImpl::create(L);
}


LuaObject::LuaObject(LuaObjectImpl* impl)
{
	if(impl)
	{
		assert(impl->getRef()==1);
	}
	m_ptr=impl;
}

LuaObject::LuaObject(const LuaObject& p)
	: m_ptr(p.m_ptr) 
{
	if (m_ptr)m_ptr->addRef();
}

LuaObject LuaObject::objFromIndex(LuaState* L,int idx)
{
	return LuaObjectImpl::createFromIndex(L,idx);
}


LuaObject::~LuaObject(void)
{
	if (m_ptr) m_ptr->release();
}

int LuaObject::getIndex()const
{
	assert (m_ptr);
	return m_ptr->getIndex();
}

const char* LuaObject::typeName()const
{
	if (m_ptr)
		return lua_typename(m_ptr->getLuaState(),m_ptr->getIndex());
	else
		return "None";
}

int  LuaObject::getType()const
{
	if (m_ptr)
		return lua_type(m_ptr->getLuaState(),m_ptr->getIndex());
	else
		return LUA_TNONE;
}

bool LuaObject::isNumber()const
{
	return getType()==LUA_TNUMBER;
}
bool LuaObject::isString()const
{
	return getType()==LUA_TSTRING;
}
bool LuaObject::isCFunction()const
{
	return getType()==LUA_TFUNCTION;
}
bool LuaObject::isFunction()const
{
	return getType()==LUA_TFUNCTION;
}
bool LuaObject::isUData()const
{
	return getType()==LUA_TUSERDATA;
}
bool LuaObject::isTable()const
{
	return getType()==LUA_TTABLE;
}
bool LuaObject::isNil()const
{
	return getType()==LUA_TNIL;
}
bool LuaObject::isBool()const
{
	return getType()==LUA_TBOOLEAN;
}
bool LuaObject::isThread()const
{
	return getType()==LUA_TTHREAD;
}
bool LuaObject::isNone()const
{
	return getType()==LUA_TNONE;
}

lua_Number LuaObject::toNumber()const
{
	assert(m_ptr);
	return lua_tonumber(m_ptr->getLuaState(),m_ptr->getIndex());
}
lua_Integer LuaObject::toInt()const
{
	assert(m_ptr);
	return lua_tointeger(m_ptr->getLuaState(),m_ptr->getIndex());
}
bool LuaObject::toBool()const
{
	assert(m_ptr);
	return lua_toboolean(m_ptr->getLuaState(),m_ptr->getIndex())!=0;
}
const char* LuaObject::toString()const
{
	assert(m_ptr);
	return lua_tostring(m_ptr->getLuaState(),m_ptr->getIndex());
}
lua_CFunction LuaObject::toCFunction()const
{
	assert(m_ptr);
	return lua_tocfunction(m_ptr->getLuaState(),m_ptr->getIndex());
}
void * LuaObject::toData()const
{
	assert(m_ptr);
	return lua_touserdata(m_ptr->getLuaState(),m_ptr->getIndex());
}

void * LuaObject::checkData(const char* type)const
{
	assert(m_ptr);
	return luaL_checkudata(m_ptr->getLuaState(),m_ptr->getIndex(),type);
}

lua_State* LuaObject::toThread()const
{
	assert(m_ptr);
	return lua_tothread(m_ptr->getLuaState(),m_ptr->getIndex());
}
const void* LuaObject::toPointer()const
{
	assert(m_ptr);
	return lua_topointer(m_ptr->getLuaState(),m_ptr->getIndex());
}

size_t LuaObject::objLen()const
{
	assert(m_ptr);
	return lua_objlen(m_ptr->getLuaState(),m_ptr->getIndex());
}


LuaObject& LuaObject::operator=(const LuaObject& other)
{
	lua_pushvalue(m_ptr->getLuaState(),other.getIndex());
	lua_replace(m_ptr->getLuaState(),m_ptr->getIndex());
	return *this;
}

bool LuaObject::operator==(lua_Integer n)
{
	return toInt()==n;
}

bool LuaObject::operator==(const char* s)
{
	if(isString() && s)
		return strcmp(toString(),s)==0;
	else
		return false;
}


lua_State* LuaObject::getLuaState()
{
	assert (m_ptr);
	return m_ptr->getLuaState();
}

LuaState* LuaObject::getCppLuaState()
{
	assert (m_ptr);
	return m_ptr->getCppLuaState();
}


bool LuaObject::setMetatable(LuaTable tab)
{
	if(tab.isValid())
	{
		lua_State * L=getLuaState();
		lua_pushvalue(L,tab.getIndex());
		return lua_setmetatable(L,getIndex())==LUA_OK;
	}
	return false;
}

LuaTable LuaObject::getMetatable()
{
	lua_State * L=getLuaState();
	lua_getmetatable(L,getIndex());
	return LuaObject::objFromIndex(getCppLuaState(),lua_gettop(L));
}





