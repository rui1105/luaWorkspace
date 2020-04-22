#include<iostream>


extern "C"
{
    #include "lua.h"
    #include "lauxlib.h" // many function begins with "LuaL_"
    #include "lualib.h"
}

static int sum(int a, int b);
static int lsum(lua_State *L);


static int sum(int a, int b)
{
    return a + b;
}

static int lsum(lua_State *L)
{
    int a = (int)lua_tonumber(L, -1);
    int b = (int)lua_tonumber(L, -2);
    lua_pushnumber(L, sum(a, b));
    return 1;
}

/**
 * 
 * C host pagram
 * 
 * */
int main()
{
    lua_State *L = luaL_newstate();

    luaL_openlibs(L);

    lua_register(L, "sum", lsum);

    int err = luaL_dofile(L, "../test.lua");
    if (err)
    {
        return 0;
    }
    
/*
    int err = luaL_loadfile(L, "../test.lua"); // load

    if (err)
    {
        return 0;
    }

    err = lua_pcall(L, 0, 0, 0); // run

    if (err)
    {
        return 0;
    }

    lua_getglobal(L, "name"); // push
    printf("%s\n", lua_tostring(L, -1)); // pop and get and printf
*/
    lua_close(L); // free    
    
}