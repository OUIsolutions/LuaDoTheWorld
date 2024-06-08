
local dtw = require("luaDoTheWorld/luaDoTheWorld")



local elements,size = dtw.list_all_recursively("tests/target/test_dir")

for i=1,size do
	local current = elements[i]
	print(current)
end