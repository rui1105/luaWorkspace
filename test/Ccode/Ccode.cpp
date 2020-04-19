#include<iostream>
#include<string.h>

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h" // many function begins with "LuaL_"
    #include "lualib.h"
}

int main()
{
    char buff[256] = {0};
    int error;

    lua_State *L = luaL_newstate(); // open Lua 
    luaL_openlibs(L); // open standard lib

    while(fgets(buff, sizeof(buff), stdin) != NULL)
    {
        error = luaL_loadbuffer(L, buff, strlen(buff), "line")
            || lua_pcall(L, 0, 0, 0);
        
        if (error)
        {
            fprintf(stderr, "%s", lua_tostring(L, -1));
            lua_pop(L,1); // pop error info from stack
        }
        
    }

    lua_close(L);
    return 0;
}