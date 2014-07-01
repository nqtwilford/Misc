#ifndef _EPLUASCRIPTENGINE_H_
#define _EPLUASCRIPTENGINE_H_

class lua_State;
class EpLuaScriptEngine
{
public:
	EpLuaScriptEngine();
	virtual ~EpLuaScriptEngine();

	bool LoadScript(const char *fileName);
	bool GetInt(const char *field, int *ret);
	bool GetBool(const char *field, bool *ret);
	bool GetFloat(const char *field, float *ret);
	bool GetString(const char *field, const char **ret);
	bool GetTSize(const char *table, int *size);
	bool GetTInt(const char *table, int idx, int *ret);
	bool GetTFloat(const char *table, int idx, float *ret);
	bool GetTString(const char *table, int idx, const char **ret);

protected:
	lua_State *m_L;
};
#endif
