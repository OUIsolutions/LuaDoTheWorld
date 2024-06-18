


local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
	print("aaaa")
end)

fork.wait(100)

print("fora")
