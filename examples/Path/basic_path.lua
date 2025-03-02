local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
local name = path.get_name()
local dir = path.get_dir()
local extension = path.get_extension()
print("name",name)
print("dir",dir)
print("extension",extension)