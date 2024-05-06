


local dtw = require("luaDoTheWorld/luaDoTheWorld")

 dtw.newResource("a")
.sub_resource("b.txt")
.set_value("aaaa")
.set_extension("xml")
.commit()
