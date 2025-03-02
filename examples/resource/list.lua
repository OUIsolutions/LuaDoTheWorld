local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local elements,size = a.list()

for i=1,size do
    local value = elements[i]
	print("path",value.get_path_string())
	print("type",value.get_type())
end


