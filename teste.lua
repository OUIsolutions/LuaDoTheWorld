


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c/")
local elements,size = path.unpack()

for i=1,size do
	print(elements[i])
end