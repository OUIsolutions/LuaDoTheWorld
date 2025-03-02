local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local size = tree.count(function (element)

	if element.path.get_extension() == "py" then
		return true
	end
end)


print(size)