#include "LuaState.h"
#include "LuaObjectImpl.h"
#include "LuaTable.h"
#include "LuaFunction.h"
#include "Utf.h"

void LuaObjectStack::push(LuaObjectImpl* impl)
{
	m_data.push_back(impl);
	//printf("push(%d,%d)\n",m_data.size(),impl->getIndex());
}

void LuaObjectStack::pop(LuaObjectImpl* impl)
{
	for (int i=m_data.size()-1;i>=0;--i)
	{
		if (m_data[i]==impl)
		{
			m_data.erase(m_data.begin()+i);
			break;
		}
		else
			m_data[i]->decIndex();
	}

	//printf("pop(%d,%d)\n",m_data.size(),impl->getIndex());
}




LuaState::LuaState(lua_State* L)
	:m_ls(L),m_type(LST_STACK)
{
}


LuaState::~LuaState(void)
{
}

LuaObject LuaState::getGlobal(const char* name)
{
	return LuaObjectImpl::createGetGlobal(this,name);
}

LuaObject LuaState::getRegistery(const char* key)
{
	return LuaObjectImpl::createGetRegistery(this,key);
}

LuaObject LuaState::getRegistery(void* key)
{
	return LuaObjectImpl::createGetRegistery(this,key);
}

void LuaState::setRegistry(const char* key,const LuaObject obj)
{
	lua_pushstring(m_ls,key);
	lua_pushvalue(m_ls,obj.getIndex());
	lua_settable(m_ls, LUA_REGISTRYINDEX);
}

void LuaState::setRegistry(const void *key,const LuaObject obj)
{
	lua_pushlightuserdata(m_ls,const_cast<void*>(key));
	lua_pushvalue(m_ls,obj.getIndex());
	lua_settable(m_ls, LUA_REGISTRYINDEX);
}



void LuaState::setGlobal(const char* name,LuaObject obj)
{
	lua_pushvalue(m_ls,obj.getIndex());
	lua_setglobal(m_ls,name);
}



LuaObject LuaState::newNil()
{
	return LuaObjectImpl::create(this);
}

LuaObject LuaState::newNumber(lua_Number num)
{
	return LuaObjectImpl::create(this,num);
}

LuaObject LuaState::newInt(lua_Integer num)
{
	return LuaObjectImpl::create(this,num);
}


LuaObject LuaState::newString(const char*str,int len)
{
	return LuaObjectImpl::create(this,str,len);
}

LuaObject LuaState::newString(const wchar_t* utf16,int len)
{
	int utf8len=UTF16To8(NULL,(unsigned short*)utf16,0);
	UtfBuffer<128> buf;
	buf.malloc((utf8len+1)*sizeof(char));
	UTF16To8((char*)buf.getBuf(),(unsigned short*)utf16,utf8len+1);
	return LuaObjectImpl::create(this,(char*)buf.getBuf(),utf8len);
}



LuaObject LuaState::newPtr(void* p)
{
	return LuaObjectImpl::create(this,p);
}

LuaObject LuaState::newData(void* p,size_t sz)
{
	return LuaObjectImpl::create(this,p,sz);
}


LuaObject LuaState::newBool(bool b)
{
	return LuaObjectImpl::create(this,b);
}

LuaObject LuaState::newFunction(lua_CFunction f)
{
	return LuaObjectImpl::create(this,f);
}

LuaObject LuaState::newFunction(LuaCFunction f)
{
	return LuaObjectImpl::create(this,f);
}


LuaTable LuaState::newTable()
{
	return LuaObjectImpl::createTable(this);
}

LuaTable LuaState::newLib(const LuaReg funcs[])
{
	LuaTable lib=LuaObjectImpl::createTable(this);

	for (int i=0;funcs[i].funcName &&funcs[i].func ;++i)
	{
		lib.setTable(funcs[i].funcName,newFunction(funcs[i].func));
	}
	return lib;
}

void LuaState::openLib(const char* name,lua_CFunction openfunc)
{
	int top=lua_gettop(m_ls);
	openfunc(m_ls);
	lua_setglobal(m_ls,name);
	lua_settop(m_ls,top);
}


LuaObject LuaState::doFile(const char *fileName)
{
	if((luaL_loadfile(m_ls, fileName) || lua_pcall(m_ls, 0, 1, 0))!=0)
	{
		std::string err=lua_tostring(m_ls,-1);
		lua_pop(m_ls,1);
		throw LuaException(err.c_str());
		return LuaObjectImpl::create(this);
	}
	else
	{
		return LuaObject::objFromIndex(this,lua_gettop(m_ls));
	}
}


LuaObject LuaState::doString(const char *fileName)
{
	if((luaL_loadstring(m_ls, fileName) || lua_pcall(m_ls, 0, 1, 0))!=0)
	{
		std::string err=lua_tostring(m_ls,-1);
		lua_pop(m_ls,1);
		throw LuaException(err.c_str());
		return LuaObjectImpl::create(this);
	}
	else
	{
		return LuaObject::objFromIndex(this,lua_gettop(m_ls));
	}
}

LuaObject LuaState::require(const char *file)
{
	LuaFunction require=getGlobal("require");
	if (require.isValid())
	{
		return require(file);
	}
	return newNil();
}



void LuaState::error(const char* fmt,...)
{
	va_list argp;
	va_start(argp, fmt);
	luaL_where(m_ls, 1);
	lua_pushvfstring(m_ls, fmt, argp);
	va_end(argp);
	lua_concat(m_ls, 2);
	lua_error(m_ls);
}



void LuaState::enumStack()
{
	lua_State *L=m_ls;
	int top = lua_gettop(L);

	printf("enumStack**************************\n");

	printf("Type:%d", top);
	for(int i=1; i<=lua_gettop(L); ++i)
	{
		switch(lua_type(L, i))
		{
		case LUA_TNIL:
			printf( "\t%s", lua_typename(L, lua_type(L, i)));
			break;
		case LUA_TBOOLEAN:
			printf("\t%s	%s", lua_typename(L, lua_type(L, i)), lua_toboolean(L, i)?"true":"false");
			break;
		case LUA_TLIGHTUSERDATA:
			printf("\t%s	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TNUMBER:
			printf("\t%s	%f", lua_typename(L, lua_type(L, i)), lua_tonumber(L, i));
			break;
		case LUA_TSTRING:
			printf("\t%s	%s", lua_typename(L, lua_type(L, i)), lua_tostring(L, i));
			break;
		case LUA_TTABLE:
			printf("\t%s	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TFUNCTION:
			printf("\t%s()	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TUSERDATA:
			printf("\t%s	0x%08p", lua_typename(L, lua_type(L, i)), lua_topointer(L, i));
			break;
		case LUA_TTHREAD:
			printf("\t%s", lua_typename(L, lua_type(L, i)));
			break;
		}
	}

	printf("\n**************************enumStack\n");
}