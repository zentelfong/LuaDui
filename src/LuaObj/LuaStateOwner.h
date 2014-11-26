#pragma once
#include "LuaState.h"


//用于初始化的lua
class LuaStateOwner:public LuaState
{
public:

	LuaStateOwner()
		:m_pool(0,false),LuaState(NULL),m_errorHandler(NULL)
	{
		m_type=LST_OWNER;
		m_ls=lua_newstate(luaAlloc,&m_pool);
		luaL_openlibs(m_ls);//初始化库
		lua_settop(m_ls,0);//清空栈
	}

	~LuaStateOwner()
	{
		lua_close(m_ls);

		mallinfo info=m_pool.mallinfo();
		m_ls=NULL;
	}

	static void * luaAlloc(void *ud, void *ptr, size_t osize, size_t nsize);//内存分配

	MemPool* getMemPool(){return &m_pool;}

	virtual void error(const char* errorMsg,...);

	void setErrorHandler(LuaErrorHandler handler){m_errorHandler=handler;}
private:
	MemPool m_pool;//内存分配池
	LuaErrorHandler m_errorHandler;//错误处理函数
};