#include "LuaObjectImpl.h"
#include "LuaTable.h"
#include "LuaState.h"


int LuaObjectImpl::callDelegate(lua_State* L)
{
	int nreturn=0;
	LuaState LS(L);
	{
		LuaCFunction func =*((LuaCFunction*)(lua_touserdata(L, lua_upvalueindex(1))));
		LuaTable args=LS.newTable();//入口参数

		for (int i=1;i<=lua_gettop(L);++i)
		{
			lua_pushnumber(L,i);
			lua_pushvalue(L,i);
			lua_settable(L,args.getIndex());
		}
		try{
			nreturn=func(LS,args);
		}
		catch(LuaException e)
		{
			lua_pushstring(L,e.what());
			return lua_error(L);
		}
		catch(std::exception& e)
		{
			lua_pushstring(L,e.what());
			return lua_error(L);
		}
		catch(const char *s)
		{
			lua_pushstring(L,s);
			return lua_error(L);
		}
		catch(...)
		{
			lua_pushliteral(L, "caught (...)");
			return lua_error(L);
		}
	}
	//LS.enumStack();
	return nreturn;
}



LuaObjectImpl* LuaObjectImpl::createFromIndex(LuaState* L,int idx)
{
	//申请内存
	void* pool=NULL;
	lua_Alloc alloc=lua_getallocf(L->getLuaState(),(void**)&pool);
	LuaObjectImpl* impl=(LuaObjectImpl*)alloc(pool,NULL,0,sizeof(LuaObjectImpl));

	impl->m_ls=L;
	impl->m_ref=1;
	impl->m_index=idx;

	L->getStack()->push(impl);
	return impl;
}

LuaObjectImpl* LuaObjectImpl::createFromTop(LuaState* L)
{
	return createFromIndex(L,lua_gettop(L->getLuaState()));
}

void LuaObjectImpl::free()
{
	m_ls->getStack()->pop(this);
	lua_remove(getLuaState(),m_index);
	//释放内存
	void* pool=NULL;
	lua_Alloc alloc=lua_getallocf(getLuaState(),(void**)&pool);
	alloc(pool,this,sizeof(LuaObjectImpl),0);
}


lua_State* LuaObjectImpl::getLuaState()
{
	return m_ls->getLuaState();
}


LuaObjectImpl* LuaObjectImpl::create(LuaState* L)
{
	lua_pushnil(L->getLuaState());
	return createFromTop(L);
}



LuaObjectImpl* LuaObjectImpl::create(LuaState* L,lua_Integer num)
{
	lua_pushinteger(L->getLuaState(),num);
	return createFromTop(L);
}


LuaObjectImpl* LuaObjectImpl::create(LuaState* L,lua_Number num)
{
	lua_pushnumber(L->getLuaState(),num);
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::create(LuaState* L,const char* str,int len)
{
	if(len<0)
		lua_pushstring(L->getLuaState(),str);
	else
		lua_pushlstring(L->getLuaState(),str,len);
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::create(LuaState* L,bool b)
{
	lua_pushboolean(L->getLuaState(),b);
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::create(LuaState* L,void* ptr)
{
	lua_pushlightuserdata(L->getLuaState(),ptr);
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::create(LuaState* L,LuaCFunction f)
{
	unsigned char* buffer = (unsigned char*)lua_newuserdata(L->getLuaState(), sizeof(f));
	memcpy(buffer, &f, sizeof(f));
	lua_pushcclosure(L->getLuaState(),callDelegate,1);	
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::create(LuaState* L,void* ud,size_t len)
{
	void* mem=lua_newuserdata(L->getLuaState(),len);
	memcpy(mem,ud,len);
	return createFromTop(L);
}	



LuaObjectImpl* LuaObjectImpl::createTable(LuaState* L)
{
	lua_newtable(L->getLuaState());
	return createFromTop(L);
}


//从全局进行初始化
LuaObjectImpl* LuaObjectImpl::createGetGlobal(LuaState* L,const char* name)
{
	lua_getglobal(L->getLuaState(),name);
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::createGetRegistery(LuaState* L,const char* key)
{
	lua_pushstring(L->getLuaState(), key);   /* push kry*/
	lua_gettable(L->getLuaState(), LUA_REGISTRYINDEX);  /* retrieve value */
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::createGetRegistery(LuaState* L,void* key)
{
	lua_pushlightuserdata(L->getLuaState(), key);   /* push kry*/
	lua_gettable(L->getLuaState(), LUA_REGISTRYINDEX);  /* retrieve value */
	return createFromTop(L);
}	

LuaObjectImpl* LuaObjectImpl::createGetTable(LuaState* L,LuaObjectImpl* tab,const char* key)
{
	lua_pushstring(L->getLuaState(),key);
	lua_gettable(L->getLuaState(),tab->getIndex());
	return createFromTop(L);
}

LuaObjectImpl* LuaObjectImpl::createGetTable(LuaState* L,LuaObjectImpl* tab,lua_Integer key)
{
	lua_pushinteger(L->getLuaState(),key);
	lua_gettable(L->getLuaState(),tab->getIndex());
	return createFromTop(L);
}
















