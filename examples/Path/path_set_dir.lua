local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.set_dir("test")
print(path.get_full_path())