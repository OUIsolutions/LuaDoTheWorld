local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local b = a.sub_resource("b.txt")
b.set_value("content of b1")
a.commit()
