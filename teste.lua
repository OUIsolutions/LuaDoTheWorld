


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local r  = dtw.newResource("a")

r["b"]["c"].set_value("porra")


r.commit()