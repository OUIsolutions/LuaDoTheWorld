local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree()
local a = tree.newTreePart_empty("tests/target/Tree/a.txt")
a.set_value("content of a")
a.hardware_write()
local b = tree.newTreePart_empty("tests/target/Tree/b.txt")
a.set_value("content of b")
a.hardware_write()

tree.commit()