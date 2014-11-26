
#ifndef COMMON_H
#define COMMON_H


extern "C" {
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
}

#include <string.h>
#include <assert.h>
#include <string>
#include <vector>
#include "MemPool.h"
#include "Utf.h"

#define ZTLUA_NAME_OF_NAMESPACE lua

#define ZTLUA_NAMESPACE_BEGIN namespace ZTLUA_NAME_OF_NAMESPACE{
#define ZTLUA_NAMESPACE_END }

#define ZTLUA_NAMESPACE ZTLUA_NAME_OF_NAMESPACE

#define ZTLUA_USE_NAMESPACE using namespace ZTLUA_NAME_OF_NAMESPACE;


#define LUA_OK 0

class LuaState;
class LuaObject;
class LuaTable;


typedef int (*LuaCFunction) (LuaState& L,LuaTable& arg);

struct LuaReg
{
	const char* funcName;
	LuaCFunction func;
};


struct lua_index
{
	int index;
};


#endif
