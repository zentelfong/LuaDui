
#include <stdio.h>
#include "Luaobj.h"

LuaObject test(LuaState* L,LuaObject arg1)
{
	LuaObject t1=L->newString("123");


	LuaObject t2=L->newString("456");


	return t1;
}



int TestLuaFunction (LuaState& L,LuaTable& arg)
{
	const char* arg1=arg.getTable(1).toString();
	const char* arg2=arg.getTable(2).toString();
	return L.lreturn(test(&L,arg));
}



void main()
{
	LuaEngine L;


	LuaEngine* pL=LuaManager::instance()->current();
	{
		LuaObject obj=L.newFunction(TestLuaFunction);
		L.setGlobal("cfunc",obj);
	}

	printf("-------------------------------------------------\n");

	L.doFile("test.lua");

	int top3=L.getTop();
	{
		LuaFunction func=L.getGlobal("test");

		func("123","456");
	}


	getchar();
}






















