local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
local sub_dirs = path.get_sub_dirs_from_index(1,-1)
print(sub_dirs)