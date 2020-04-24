-- Scheme compiler git clone https://github.com/cisco/ChezScheme
-- Scheme first www.ibm.com/developerworks/cn/linux/l-schm/index1.html

-- Haskell functional programme language
-- www.haskell.org

-- below from www.lua.org/manual/5.3/manual.html

--[[
lua_State

lua_Number lua_tonumber(lua_State *L, int index)
lua_Number lua_tonumber(lua_State *L, int index, int *isnum)

lua_pushnumber(lua_State *L, lua_Number n)

lua_State *luaL_newstate(void)
void luaL_openlibs(lua_State *L)

void lua_register(lua_State *L, const char *name, lua_CFunction f) -- It is a macro.

lua_close(lua_State *L)

-- some note begin

typedef int (*lua_CFunction) (lua_State *L) -- type for C function
(C/C++) to communicate with Lua, there is a protocol:

C/C++ calls Lua:???


lua calls C/C++:???

-- some note end

--]]



--[[
C API

lua_xxx

lua_getxxx()
lua_isxxx()
lua_newxxx()
lua_pxxx()
lua_pushxxx()
lua_rawxxx()
lua_setxxx()
lua_toxxx()
lua_typexxx()
lua_upvaluexxx()
lua_yieldxxx()

......

--]]


--[[
auxiliry library

luaL_addxxx()
luaL_argxxx()
luaL_buffinitxxx()
luaL_checkxxx()
luaL_doxxx()
luaL_getxxx()
luaL_loadxxx()
luaL_newxxx()
luaL_prepxxx()
luaL_pushxxx()
luaL_setxxx()

.....

--]]


--[[
standard library

??? = base, coroutine, debug, io, math, os, package, string, table, utf8
luaopen_???

They are functions, which are declared in lualib.h

we can open them all by luaL_openlibs() or individually by luaL_requiref()

stl provides functions that are implemented by C API

except base and package stl, others have a role ,
such as fields of a global table or methods of its object
--]]

--[[
contants

LUA_XXX

.....

--]]

--[[
environment variables

LUA_CPATH
LUA_PATH
LUA_INIT

.....

--]]


