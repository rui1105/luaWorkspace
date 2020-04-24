#include <iostream>
#include <lua.hpp>

extern "C" {
    static int luacppfunction(lua_State *L) {
        double arg = luaL_checknumber(L, 1);
        lua_pushnumber(L, arg * 5);
        return 1;
    }
}

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

// from www.indienova.com/u/eastecho
int main()
{
    //****************************
    // init
    lua_State *L;
    L = luaL_newstate();
    
    luaL_openlibs(L);

    // loading lua file, handl loading error
    if (luaL_loadfile(L, "../luascript.lua"))
    {
        cerr << "loading fail..." << endl;
        cerr << lua_tostring(L, -1) << endl;
        lua_pop(L, 1);
    }
    //*****************************


    //*****************************
    // writing cppvar from C++
    lua_pushnumber(L, 11);
    lua_setglobal(L, "cppvar");

    // executing lua file, handl executing error 
    if (lua_pcall(L, 0, LUA_MULTRET, 0))
    {
        cerr << "executing fail..." << endl;
        cerr << lua_tostring(L, -1) << endl;
        lua_pop(L, 1);
    }
    //*****************************


    //*****************************
    // reading luavar from Lua
    lua_getglobal(L, "luavar");
    double luavar = lua_tonumber(L, -1);
    lua_pop(L, 1);

    cout << "luavar : " << luavar << endl;
    //*****************************


    //*****************************
    // C++ calls Lua
    lua_getglobal(L, "myluafunction");
    lua_pushnumber(L, 5);
    lua_pcall(L, 1, 1, 0);
    cout << "return result: " << lua_tostring(L, -1) << endl;
    lua_pop(L, 1);
    //*****************************


    //*****************************
    // Lua calls C++
    lua_pushcfunction(L, luacppfunction);
    lua_setglobal(L,"cppfunction");

    // C++ calls Lua to execute C++ function
    lua_getglobal(L, "myfunction");
    lua_pushnumber(L, 5);
    lua_pcall(L, 1, 1, 0);
    cout << "return result: " << lua_tonumber(L, -1) << endl;
    lua_pop(L, 1);
    //*****************************

    
    lua_close(L);

    return 0;

}