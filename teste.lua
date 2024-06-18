


local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
	for i=1,10 do
		print("aaaa")
	end
end)

local fork2 = dtw.newFork(function ()
	for i=1,10 do
		print("bbb")
	end
end)

while  fork.is_alive() do
end
while  fork2.is_alive() do
end
print("fora")
