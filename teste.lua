


local dtw = require("luaDoTheWorld/luaDoTheWorld")
local value = dtw.newResource("clib")["declaration.h"]

dtw.write_file("teste.txt",value)