local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

tree.each(function (element)

	if element.path.get_extension()== "txt" then
		element.path.set_extension("py")
	end
	element.hardware_modify()
end)

tree.commit()