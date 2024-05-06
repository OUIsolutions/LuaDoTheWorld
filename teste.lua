


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local value = dtw.newResource("a")
local b = value.sub_resource("b.txt")
b.set_extension("json")
value.commit()

