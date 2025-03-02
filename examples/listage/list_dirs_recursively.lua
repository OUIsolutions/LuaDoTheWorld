
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false

local dirs,size = dtw.list_dirs_recursively("tests/target/test_dir",concat_path)



for i=1,size do
	local current = dirs[i]
	print(current)
end