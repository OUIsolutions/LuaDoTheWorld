


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local clib = dtw.newResource("clib")
clib.each(function (value)
	print(value.get_path_string())
end)