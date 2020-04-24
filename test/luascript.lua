print("Lua's abc")

print("Lua reads from C++ ", cppvar)
luavar = cppvar * 3

function myluafunction(times)
  return string.rep("(-)", times)
end

function myfunction(arg)
  return cppfunction(arg)
end