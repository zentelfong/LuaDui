#pragma once

extern "C"
{
	struct lua_State;
	int luaopen_luv (lua_State *L);
	int luv_do_loop_work(lua_State *L);
};