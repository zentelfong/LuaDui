#pragma once
#include <stdint.h>
#include "LuaStateOwner.h"

class LuaEngine;

class LuaManager
{
public:
	LuaManager(void);
	~LuaManager(void);

	static LuaManager* instance();//全局
	LuaEngine* current();//获取当前线程的lua引擎,如果当前线程没有使用则返回NULL

private:
	friend class LuaEngine;
	void setCurrent(LuaEngine* engine);
	uint32_t m_key;
};


//lua引擎
class LuaEngine:public LuaStateOwner
{
public:
	LuaEngine();
	~LuaEngine();

	//其他扩展

};


/*
int threadFunc(void* d)
{
	LuaEngine engine;

	//之后可以在线程内使用获取当前线程的lua引擎
	LuaEngine* lua=LuaManager::instance()->current()


}


*/
