
local dtw = require("luaDoTheWorld/luaDoTheWorld")



local files,size = dtw.list_files("tests/target/test_dir")


for i=1,size do
	local current = files[i]
	print(current)
end