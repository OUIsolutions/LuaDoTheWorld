local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.insert_dir_after("a","inserted_dir")
print(path.get_full_path())