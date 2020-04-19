#include<iostream>


extern "C"
{
    #include "lua.h"
    #include "lauxlib.h" // many function begins with "LuaL_"
    #include "lualib.h"
}


int main() {
    // create a new stack
    lua_State *L = luaL_newstate();

    //push a string to stack
    lua_pushstring(L, "zxlhc");
    //push a number to stack
    lua_pushnumber(L, 30);

    if (lua_isstring(L, 1))
    {
        printf("%s\n", lua_isstring(L, 1));
    }

    if (lua_isstring(L, -1))
    {
        printf("%s\n", lua_isnumber(L, 2));
    }

    lua_close(L);
    
}