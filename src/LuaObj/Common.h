
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


#define LUA_OK 0

class LuaState;
class LuaTable;

typedef LuaTable (*LuaCFunction) (LuaState *L,LuaTable* arg);



struct lua_index
{
	int index;
};

#endif
