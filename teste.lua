


local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
	while true do
		
	end
end)

local fork2 = dtw.newFork(function ()
	while true do

	end
end)

fork.wait(3000)
fork2.wait(3000)

print("fora")
