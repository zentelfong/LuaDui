#pragma once
#include "LuaCommon.h"


class LuaObjectStack;

class LuaObjectData
{
public:
	LuaObjectData(LuaObjectStack* ls,int idx)
		:m_lstack(ls),m_ref(1),m_index(idx)
	{
	}


	int addRef()
	{
		return ++m_ref;
	}

	int release();

	int getRef()
	{
		return m_ref;
	}

	int getIndex()const
	{
		return m_index;
	}

	lua_State* getLuaState()const;
	LuaObjectStack* getLuaObjectStack(){return m_lstack;}
private:
	friend class LuaObjectStack;

	LuaObjectStack* m_lstack;
	int m_ref;
	int m_index;//-1表示未初始化
};


class LuaObjectStack
{
public:
	LuaObjectStack(lua_State * L)
		:m_ls(L),m_data(NULL),m_top(0),m_size(0)
	{
		assign(128);
	}


	~LuaObjectStack(void)
	{
		free(m_data);
	}

	void assign(size_t count)
	{
		m_data=(LuaObjectData*)realloc(m_data,count*sizeof(LuaObjectData));
		m_size=count;
	}


	//压入c栈保存
	LuaObjectData* push(int luaidx)
	{
		if (++m_top>m_size)
		{
			assign(m_size*2);
		}
		LuaObjectData* data=&m_data[m_top];
		data->m_index=luaidx;
		data->m_lstack=this;
		data->m_ref=1;
		return data;
	}

	void pop(LuaObjectData* data)
	{
		for (size_t i=m_top;i>0;--i)
		{
			if (data==&m_data[i])
			{
				lua_remove(m_ls,data->m_index);//从lua栈中移除
				data->m_ref=0;
				data->m_index=-1;
				break;
			}
			else
			{
				--m_data[i].m_index;
			}
		}
	}


	lua_State* getLuaState()const
	{
		return m_ls;
	}

	LuaObjectData* createFromIndex(int idx)
	{
		return push(idx);
	}


	//nil
	LuaObjectData* create()
	{
		lua_pushnil(m_ls);
		return push(lua_gettop(m_ls));
	}

	//number
	LuaObjectData* create(lua_Integer num)
	{
		lua_pushinteger(m_ls,num);
		return push(lua_gettop(m_ls));
	}

	LuaObjectData* create(lua_Number num)
	{
		lua_pushnumber(m_ls,num);
		return push(lua_gettop(m_ls));
	}

	//string
	LuaObjectData* create(const char* str,int len=-1)
	{
		if(len<0)
			lua_pushstring(m_ls,str);
		else
			lua_pushlstring(m_ls,str,len);
		return push(lua_gettop(m_ls));
	}

	//bool
	LuaObjectData* create(bool b)
	{
		lua_pushboolean(m_ls,b);
		return push(lua_gettop(m_ls));
	}

	LuaObjectData* create(void* ptr)
	{
		lua_pushlightuserdata(m_ls,ptr);
		return push(lua_gettop(m_ls));
	}


	static int callDelegate(lua_State* L);

	LuaObjectData* create(LuaCFunction f)
	{
		unsigned char* buffer = (unsigned char*)lua_newuserdata(m_ls, sizeof(f));
		memcpy(buffer, &f, sizeof(f));
		lua_pushcclosure(m_ls,callDelegate,1);	
		return push(lua_gettop(m_ls));
	}



	LuaObjectData* create(void* ud,size_t len)
	{
		void* mem=lua_newuserdata(m_ls,len);
		memcpy(mem,ud,len);
		return push(lua_gettop(m_ls));
	}	

	LuaObjectData* createTable(int arrSize,int hashSize)
	{
		lua_createtable(m_ls,arrSize,hashSize);
		return push(lua_gettop(m_ls));
	}


	//从全局进行初始化
	LuaObjectData* createGetGlobal(const char* name)
	{
		lua_getglobal(m_ls,name);
		return push(lua_gettop(m_ls));
	}

	LuaObjectData* createGetRegistery(const char* key)
	{
		lua_pushstring(m_ls, key);   /* push kry*/
		lua_gettable(m_ls, LUA_REGISTRYINDEX);  /* retrieve value */
		return push(lua_gettop(m_ls));
	}

	LuaObjectData* createGetRegistery(void* key)
	{
		lua_pushlightuserdata(m_ls, key);   /* push kry*/
		lua_gettable(m_ls, LUA_REGISTRYINDEX);  /* retrieve value */
		return push(lua_gettop(m_ls));
	}	

	LuaObjectData* createGetTable(LuaObjectData* tab,const char* key)
	{
		lua_pushstring(m_ls,key);
		lua_gettable(m_ls,tab->getIndex());
		return push(lua_gettop(m_ls));
	}

	LuaObjectData* createGetTable(LuaObjectData* tab,lua_Integer key)
	{
		lua_pushinteger(m_ls,key);
		lua_gettable(m_ls,tab->getIndex());
		return push(lua_gettop(m_ls));
	}


private:
	friend class LuaStateOwner;
	lua_State* m_ls;
	LuaObjectData* m_data;
	size_t m_top;
	size_t m_size;
};

