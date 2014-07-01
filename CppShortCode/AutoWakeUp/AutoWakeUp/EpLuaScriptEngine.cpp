#include <iostream>
#include <lua.hpp>
#include "EpLuaScriptEngine.h"
using namespace std;

EpLuaScriptEngine::EpLuaScriptEngine()
{
	m_L = luaL_newstate();
	luaL_openlibs(m_L);
}

EpLuaScriptEngine::~EpLuaScriptEngine()
{
	lua_close(m_L);
}

bool EpLuaScriptEngine::LoadScript( const char *fileName )
{
	if (luaL_loadfile(m_L, fileName) || lua_pcall(m_L, 0, 0, 0))
	{
		cout<<lua_tostring(m_L, -1)<<endl;
		return false;
	}
	return true;
}

bool EpLuaScriptEngine::GetInt( const char *field, int *ret )
{
	int top = lua_gettop(m_L);
	lua_getglobal(m_L, field);
	if (lua_isnumber(m_L, -1))
	{
		*ret = (int)lua_tonumber(m_L, -1);
		lua_settop(m_L,top);
		return true;
	}
	else
	{
		lua_settop(m_L,top);
		return false;
	}
}

bool EpLuaScriptEngine::GetBool(const char *field, bool *ret)
{
	int top = lua_gettop(m_L);
	lua_getglobal(m_L, field);
	if(lua_isboolean(m_L, -1))
	{
		*ret = (bool)lua_toboolean(m_L, -1);
		lua_settop(m_L, top);
		return true;
	}
	else
	{
		lua_settop(m_L, top);
		return false;
	}
}

bool EpLuaScriptEngine::GetFloat( const char *field, float *ret )
{
	int top = lua_gettop(m_L);
	lua_getglobal(m_L, field);
	if (lua_isnumber(m_L, -1))
	{
		*ret = (float)lua_tonumber(m_L, -1);
		lua_settop(m_L,top);
		return true;
	}
	else
	{
		lua_settop(m_L,top);
		return false;
	}
}

bool EpLuaScriptEngine::GetString( const char *field, const char **ret )
{
	int top = lua_gettop(m_L);
	lua_getglobal(m_L, field);
	if (lua_isstring(m_L, -1))
	{
		*ret = lua_tostring(m_L, -1);
		lua_settop(m_L,top);
		return true;
	}
	else
	{
		lua_settop(m_L,top);
		return false;
	}
}

bool EpLuaScriptEngine::GetTSize(const char *table, int *size)
{
	return false;
}

bool EpLuaScriptEngine::GetTInt( const char *table, int idx, int *ret )
{
	int top = lua_gettop(m_L);
	lua_getglobal(m_L, table);
	if (!lua_istable(m_L, -1))
	{
		lua_settop(m_L,top);
		return false;
	}
	lua_rawgeti(m_L,-1,idx);
	if (!lua_isnumber(m_L,-1))
	{
		lua_settop(m_L,top);
		return false;
	}
	*ret = (int)lua_tonumber(m_L, -1);
	lua_settop(m_L,top);
	return true;
}

bool EpLuaScriptEngine::GetTFloat( const char *table, int idx, float *ret )
{
	int top = lua_gettop(m_L);
	lua_getglobal(m_L, table);
	if (!lua_istable(m_L, -1))
	{
		lua_settop(m_L,top);
		return false;
	}
	lua_rawgeti(m_L,-1,idx);
	if (!lua_isnumber(m_L,-1))
	{
		lua_settop(m_L,top);
		return false;
	}
	*ret = (float)lua_tonumber(m_L, -1);
	lua_settop(m_L,top);
	return true;
}

bool EpLuaScriptEngine::GetTString( const char *table, int idx, const char **ret )
{
	int top = lua_gettop(m_L);
	lua_getglobal(m_L, table);
	if (!lua_istable(m_L, -1))
	{
		lua_settop(m_L,top);
		return false;
	}
	lua_rawgeti(m_L,-1,idx);
	if (!lua_isstring(m_L,-1))
	{
		lua_settop(m_L,top);
		return false;
	}
	*ret = lua_tostring(m_L, -1);
	lua_settop(m_L,top);
	return true;
}
