


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local clib_tree = dtw.newTree_from_hardware("clib")

clib_tree.each(function (value)
	print(value.path.get_extension())
end)
