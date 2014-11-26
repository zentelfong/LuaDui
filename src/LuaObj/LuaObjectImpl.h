#pragma once
#include "LuaCommon.h"


class LuaObjectImpl
{
public:
	//创建
	static LuaObjectImpl* createFromIndex(LuaState* L,int idx);
	static LuaObjectImpl* createFromTop(LuaState* L);

	//nil
	static LuaObjectImpl* create(LuaState* L);

	//number
	static LuaObjectImpl* create(LuaState* L,lua_Integer num);

	static LuaObjectImpl* create(LuaState* L,lua_Number num);

	//string
	static LuaObjectImpl* create(LuaState* L,const char* str,int len=-1);

	//bool
	static LuaObjectImpl* create(LuaState* L,bool b);

	static LuaObjectImpl* create(LuaState* L,void* ptr);


	static int callDelegate(lua_State* L);

	static LuaObjectImpl* create(LuaState* L,LuaCFunction f);


	static LuaObjectImpl* create(LuaState* L,void* ud,size_t len);

	static LuaObjectImpl* createTable(LuaState* L);

	//从全局进行初始化
	static LuaObjectImpl* createGetGlobal(LuaState* L,const char* name);

	static LuaObjectImpl* createGetRegistery(LuaState* L,const char* key);

	static LuaObjectImpl* createGetRegistery(LuaState* L,void* key);	

	static LuaObjectImpl* createGetTable(LuaState* L,LuaObjectImpl* tab,const char* key);

	static LuaObjectImpl* createGetTable(LuaState* L,LuaObjectImpl* tab,lua_Integer key);

	//释放
	void free();

	int addRef()
	{
		return ++m_ref;
	}

	int release()
	{
		int count =--m_ref;
		if (!count) 
		{
			free();
		}
		return count;
	}

	int getRef()
	{
		return m_ref;
	}

	int getIndex()const
	{
		return m_index;
	}

	LuaState* getCppLuaState(){return m_ls;}
	lua_State* getLuaState();
	void decIndex(){--m_index;}
private:
	LuaState* m_ls;
	int m_ref;
	int m_index;//-1表示未初始化
};



