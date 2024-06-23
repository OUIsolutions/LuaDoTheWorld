local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")

print(a.get_value_from_sub_resource("b.txt"))