-- single line
-- C and Lua have an interact

-- multiple line
--[[ 
  1 C controls Lua
  2 Lua controls C
  
  using C API to interact, to manipulate Lua code.
  
  but how and what?
  
  Lua and C use virtual stack to communicate.
  
  Virtual stack can solve two difference:
    1 Lua gc , C free memory apperantly
    2 Lua uses dynamical style, C uses static style
    
    There are three stacks in it.
      1 Lua stack
      2 C stack
      3 the third stack which Lua and C interact
      
      One special is the index, which can point to some elements in stack, including negative and positive.
      
      The stack in C API of Lua is lua_State.
      
      Error of interacting between C++ and Lua is "undefined reference to luaL_newstate"
      
      Solution is to join the linking lib of lua when compiling the programme of C++, such as "g++ test.cpp --std=c++11 /usr/local/lib/liblua.a -o test"
      
      complementary: -ldl
      
--]]