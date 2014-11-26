#include "LuaEngine.h"

LuaManager s_LuaManager;

LuaManager::LuaManager(void)
{
	m_key=TlsAlloc();
}


LuaManager::~LuaManager(void)
{
	 TlsFree(m_key);
}


LuaManager* LuaManager::instance()
{
	return &s_LuaManager;
}

LuaEngine* LuaManager::current()
{
	return static_cast<LuaEngine *>(TlsGetValue(m_key));
}

void LuaManager::setCurrent(LuaEngine* engine)
{
	TlsSetValue(m_key, engine);
}




LuaEngine::LuaEngine()
{
	s_LuaManager.setCurrent(this);
}

LuaEngine::~LuaEngine()
{
	s_LuaManager.setCurrent(NULL);
}



















