


local dtw = require("luaDoTheWorld/luaDoTheWorld")


local clib =dtw.list_files("clib")
for i,v in ipairs(clib) do 
  print(v)
end 