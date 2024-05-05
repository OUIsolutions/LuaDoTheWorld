
os.execute("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  clib/main.c")


local dtw = require("luaDoTheWorld/luaDoTheWorld")

