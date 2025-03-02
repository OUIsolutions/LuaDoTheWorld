local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local files,size  = a.filter(function(value)
	if value.get_value() then
		return true
	end
end)


for i=1,size do
	local file = files[i]
	print(file.get_value())
end