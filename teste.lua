dtw = require("luaDoTheWorld/luaDoTheWorld")


local r = dtw.list_all_recursively("clib")

for  i,v in ipairs(r) do 
    print(v)
end 