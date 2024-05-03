local dtw = require("luaDoTheWorld/luaDoTheWorld")


local r = dtw.newResource("a")

local deer = r["deer.jpg"].get_value()

dtw.write_file("nada.jpg",deer)
