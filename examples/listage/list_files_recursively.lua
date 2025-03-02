
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false

local files,size = dtw.list_files_recursively("tests/target/test_dir",concat_path)

for i=1,size do
	local current = files[i]
	print(current)
end