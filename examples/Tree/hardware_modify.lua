local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
        return true;
	end
end)
target.path.set_name("new_name.txt")
target.hardware_modify()

tree.commit()

