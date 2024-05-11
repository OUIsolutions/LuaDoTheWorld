






local dtw = require("luaDoTheWorld/luaDoTheWorld")

local elements = dtw.newResource("clib")

for i,v in ipairs(elements.list() ) do
    print(v.get_path())
end