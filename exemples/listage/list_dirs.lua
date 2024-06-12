
local dtw = require("luaDoTheWorld/luaDoTheWorld")



local dirs,size = dtw.list_dirs("tests/target/test_dir")


for i=1,size do
	local current = dirs[i]
	print(current)
end