local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
a.set_value_in_sub_resource("b.txt","content of b")
a.commit()
