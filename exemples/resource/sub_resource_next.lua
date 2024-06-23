local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local next = a.sub_resource_next(".txt")
next.set_value("content generated")
a.commit()
