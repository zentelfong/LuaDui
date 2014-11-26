#pragma once

#include "LuaCommon.h"
#include "LuaObject.h"
#include "LuaStack.h"
#include "LuaException.h"


#define LUAFUNCTION_PRECALL() \
		assert(isValid());\
		lua_State* L =getLuaState();\
		lua_pushvalue(L,getIndex());


#define LUAFUNCTION_POSTCALL(numArgs) \
		if(lua_pcall(L,numArgs,1,0))\
		{\
			std::string error = lua_tostring(L, -1);\
			lua_pop(L,1);\
			throw LuaException(error);\
			return LuaObject(getCppLuaState());\
		}\
		else\
		{\
			return LuaObject::objFromIndex(getCppLuaState(),lua_gettop(L));\
		}

//调用lua函数使用
class LuaFunction:public LuaObject
{
public:
	LuaFunction(LuaState* L);
	LuaFunction(LuaObjectImpl* impl);
	LuaFunction(const LuaObject& rfs);
	LuaFunction(const LuaFunction& rfs);

	bool isValid();


	LuaObject operator()()
	{
		LUAFUNCTION_PRECALL();
		LUAFUNCTION_POSTCALL(0);
	}


	template <typename P1>
	LuaObject operator()(P1 p1)
	{
		LUAFUNCTION_PRECALL();
		StackOps::Push(L, p1);
		LUAFUNCTION_POSTCALL(1);
	}

	template <typename P1, typename P2>
	LuaObject operator()(P1 p1, P2 p2)
	{
		LUAFUNCTION_PRECALL();
		StackOps::Push(L, p1);
		StackOps::Push(L, p2);
		LUAFUNCTION_POSTCALL(2);
	}

	template <typename P1, typename P2, typename P3>
	LuaObject operator()(P1 p1, P2 p2, P3 p3)
	{
		LUAFUNCTION_PRECALL();
		StackOps::Push(L, p1);
		StackOps::Push(L, p2);
		StackOps::Push(L, p3);
		LUAFUNCTION_POSTCALL(3);
	}

	template <typename P1, typename P2, typename P3, typename P4>
	LuaObject operator()(P1 p1, P2 p2, P3 p3, P4 p4)
	{
		LUAFUNCTION_PRECALL();
		StackOps::Push(L, p1);
		StackOps::Push(L, p2);
		StackOps::Push(L, p3);
		StackOps::Push(L, p4);
		LUAFUNCTION_POSTCALL(4);
	}

	template <typename P1, typename P2, typename P3, typename P4, typename P5>
	LuaObject operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
	{
		LUAFUNCTION_PRECALL();
		StackOps::Push(L, p1);
		StackOps::Push(L, p2);
		StackOps::Push(L, p3);
		StackOps::Push(L, p4);
		StackOps::Push(L, p5);
		LUAFUNCTION_POSTCALL(5);
	}

	template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	LuaObject operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
	{
		LUAFUNCTION_PRECALL();
		StackOps::Push(L, p1);
		StackOps::Push(L, p2);
		StackOps::Push(L, p3);
		StackOps::Push(L, p4);
		StackOps::Push(L, p5);
		StackOps::Push(L, p6);
		LUAFUNCTION_POSTCALL(6);
	}

	template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	LuaObject operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
	{
		LUAFUNCTION_PRECALL();
		StackOps::Push(L, p1);
		StackOps::Push(L, p2);
		StackOps::Push(L, p3);
		StackOps::Push(L, p4);
		StackOps::Push(L, p5);
		StackOps::Push(L, p6);
		StackOps::Push(L, p7);
		LUAFUNCTION_POSTCALL(7);
	}

};

