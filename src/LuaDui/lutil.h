#include "LuaObj/Luaobj.h"


namespace lbind
{

	LuaObject toLua(LuaState& L,RECT rc);
	LuaObject toLua(LuaState& L,SIZE rc);
	LuaObject toLua(LuaState& L,POINT rc);

	RECT toRect(LuaTable obj);
	SIZE toSize(LuaTable obj);
	POINT toPoint(LuaTable obj);
}