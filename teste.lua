


local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
	for i=1,10 do
		print("aaaa")
	end
end)


print("fora")
