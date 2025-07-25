
### DtwFork
with DtwFork you can fork process easily
~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
	print("executed inside")
end)
local one_second = 1000
fork.wait(one_second)

print("executed in main prrocess")

~~~

you also can interrupt the code forcing kill

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
    while true do
	    print("executed inside")
    end
end)

local half_second = 500

fork.wait(half_second)
if fork.is_alive() then
	fork.kill()
end

print(" executed in main prrocess")
~~~