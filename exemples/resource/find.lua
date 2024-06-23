local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local element  = a.find(function(value)
	local path = dtw.newPath(value.get_path_string())
    if path.get_name() == "a.txt" then
    	return true;
    end
end)

print(element.get_value())