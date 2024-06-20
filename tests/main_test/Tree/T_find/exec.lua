local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local element = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
		return true
	end
end)

print(element.get_value())