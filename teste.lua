


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local r  = dtw.newResource("a").sub_resource(1).set_value("aaa")

r.commit()