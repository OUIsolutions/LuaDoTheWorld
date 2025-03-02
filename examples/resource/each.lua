local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
a.each(function (value)
	print("path",value.get_path_string())
	print("type",value.get_type())
end)
