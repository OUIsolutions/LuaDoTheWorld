local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local elements,size  = a.map(function(value)
	local result = {}
	result.path = value.get_path_string()
    result.value = value.get_value()
    result.type = value.get_type()
    return result;
end)
for i=1,size do
	local current = elements[i]
	print("path",current.path)
	print("value",current.value)
	print("type",current.type)
end