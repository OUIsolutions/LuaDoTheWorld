local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local b = a.sub_resource("b.txt")
b.rename("c.txt")
a.commit()
