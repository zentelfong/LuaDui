#pragma once
#include "LuaCommon.h"

namespace StackOps
{

	struct LuaLightUserData
	{
		LuaLightUserData(const void* value) :
			m_value(value)
		{
		}

		const void* m_value;
	};


	struct LuaUserData
	{
		LuaUserData(const void* value) :
			m_value(value)
		{
		}

		const void* m_value;
	};

	struct LuaNil
	{
	};

	inline void Push(lua_State* L, bool value)				{  lua_pushboolean(L, value);  }
	inline void Push(lua_State* L, char value)				{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, unsigned char value)		{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, short value)				{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, unsigned short value)	{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, int value)				{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, unsigned int value)		{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, long value)				{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, unsigned long value)		{  lua_pushnumber(L, value);  }
	inline void Push(lua_State* L, double value)			{  lua_pushnumber(L, (lua_Number)value);  }
	inline void Push(lua_State* L, float value)				{  lua_pushnumber(L, (lua_Number)value);  }
	inline void Push(lua_State* L, const char* value)		{  lua_pushstring(L, value);  }
	inline void Push(lua_State* L, const LuaNil&)			{  lua_pushnil(L);  }
	inline void Push(lua_State* L, lua_CFunction value)		{  lua_pushcclosure(L, value, 0);  }
	inline void Push(lua_State* L, const void* value)		{  lua_pushlightuserdata(L, (void*)value);  }
	inline void Push(lua_State* L, const LuaLightUserData& value)	{  lua_pushlightuserdata(L, (void*)value.m_value);  }

	static void Push(lua_State* L, const wchar_t* utf16)
	{
		int utf8len=UTF16To8(NULL,(unsigned short*)utf16,0);
		UtfBuffer<128> buf;
		buf.malloc(utf8len*sizeof(char));
		UTF16To8((char*)buf.getBuf(),(unsigned short*)utf16,utf8len);
		lua_pushlstring(L,(char*)buf.getBuf(),utf8len);
	}

	template<class T> struct TypeWrapper {};

	inline bool	Match(TypeWrapper<bool>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TBOOLEAN;  }
	inline bool	Match(TypeWrapper<char>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<unsigned char>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<short>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<unsigned short>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<int>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<unsigned int>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<long>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<unsigned long>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<float>, lua_State* L, int idx)
		{  int type = lua_type(L, idx);  return type == LUA_TNUMBER  ||  type == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<double>, lua_State* L, int idx)
		{  int type = lua_type(L, idx);  return type == LUA_TNUMBER  ||  type == LUA_TNUMBER;  }
	inline bool	Match(TypeWrapper<const char*>, lua_State* L, int idx)
		{  return lua_type(L, idx) == LUA_TSTRING;  }


	inline void				Get(TypeWrapper<void>, lua_State*, int)
		{  }
	inline bool				Get(TypeWrapper<bool>, lua_State* L, int idx)
		{  return lua_toboolean(L, idx) != 0;  }
	inline char				Get(TypeWrapper<char>, lua_State* L, int idx)
		{  return static_cast<char>(lua_tonumber(L, idx));  }
	inline unsigned char	Get(TypeWrapper<unsigned char>, lua_State* L, int idx)
		{  return static_cast<unsigned char>(lua_tonumber(L, idx));  }
	inline short			Get(TypeWrapper<short>, lua_State* L, int idx)
		{  return static_cast<short>(lua_tonumber(L, idx));  }
	inline unsigned short	Get(TypeWrapper<unsigned short>, lua_State* L, int idx)
		{  return static_cast<unsigned short>(lua_tonumber(L, idx));  }
	inline int				Get(TypeWrapper<int>, lua_State* L, int idx)
		{  return static_cast<int>(lua_tonumber(L, idx));  }
	inline unsigned int		Get(TypeWrapper<unsigned int>, lua_State* L, int idx)
		{  return static_cast<unsigned int>(lua_tonumber(L, idx));  }
	inline long				Get(TypeWrapper<long>, lua_State* L, int idx)
		{  return static_cast<long>(lua_tonumber(L, idx));  }
	inline unsigned long	Get(TypeWrapper<unsigned long>, lua_State* L, int idx)
		{  return static_cast<unsigned long>(lua_tonumber(L, idx));  }
	inline float			Get(TypeWrapper<float>, lua_State* L, int idx)
		{  return static_cast<float>(lua_tonumber(L, idx));  }
	inline double			Get(TypeWrapper<double>, lua_State* L, int idx)
		{  return static_cast<double>(lua_tonumber(L, idx));  }
	inline const char*		Get(TypeWrapper<const char*>, lua_State* L, int idx)
		{  return static_cast<const char*>(lua_tostring(L, idx));  }
	inline LuaNil			Get(TypeWrapper<LuaNil>, lua_State* L, int idx)
		{  (void)L, (void)idx;  return LuaNil();  }
	inline lua_CFunction	Get(TypeWrapper<lua_CFunction>, lua_State* L, int idx)
		{  return static_cast<lua_CFunction>(lua_tocfunction(L, idx));  }
















}