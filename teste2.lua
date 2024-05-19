
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local e = dtw.list_files_recursively("clib")
for i,v in pairs(e) do
    print(v)
end