


local dtw = require("luaDoTheWorld/luaDoTheWorld")


local clib =dtw.list_files_recursively("clib")
for i,v in ipairs(clib) do 
  print(v)
end 