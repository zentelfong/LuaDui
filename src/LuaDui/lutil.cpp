#include "lutil.h"
#include "log/log4z.h"

namespace lbind
{

	LuaObject toLua(LuaState& L,RECT rc)
	{
		LuaTable lrc=L.newTable();
		lrc.setTable("x",rc.left);
		lrc.setTable("y",rc.top);
		lrc.setTable("w",rc.right-rc.left);
		lrc.setTable("h",rc.bottom-rc.top);
		return lrc;
	}
	LuaObject toLua(LuaState& L,SIZE rc)
	{
		LuaTable lrc=L.newTable();
		lrc.setTable("w",rc.cx);
		lrc.setTable("h",rc.cy);
		return lrc;
	}
	LuaObject toLua(LuaState& L,POINT rc)
	{
		LuaTable lrc=L.newTable();
		lrc.setTable("x",rc.x);
		lrc.setTable("y",rc.y);
		return lrc;	
	}

	RECT toRect(LuaTable obj)
	{
		RECT rc;
		rc.left=obj.getTable("x").toInt();
		rc.top=obj.getTable("y").toInt();
		rc.right=rc.left+obj.getTable("w").toInt();
		rc.bottom=rc.top+obj.getTable("h").toInt();
		return rc;
	}

	SIZE toSize(LuaTable obj)
	{
		SIZE sz;
		sz.cx=obj.getTable("x").toInt();
		sz.cy=obj.getTable("y").toInt();
		return sz;	
	}

	POINT toPoint(LuaTable obj)
	{
		POINT pt;
		pt.x=obj.getTable("w").toInt();
		pt.y=obj.getTable("h").toInt();
		return pt;
	}


}