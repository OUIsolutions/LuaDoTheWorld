local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local now = a.sub_resource_now()
now.set_value("content generated")
a.commit()
