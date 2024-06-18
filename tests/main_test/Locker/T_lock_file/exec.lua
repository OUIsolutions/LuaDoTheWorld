



local dtw = require("luaDoTheWorld/luaDoTheWorld")

local locker = dtw.newLocker()
locker.lock("a.txt")
locker.unlock("a.txt");
