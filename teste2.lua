


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("teste/a/b.txt")
path.set_extension("py")

print(path)