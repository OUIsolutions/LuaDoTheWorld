


local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.copy_any_overwriting("clib","clib2")
local clib_tree = dtw.newTree_from_hardware("clib2")

clib_tree.get_tree_part_by_name("namespace.h").hardware_remove()

clib_tree.each(function (value)
	local content = value.get_value()

	if content == nil or value.is_blob()  then
		return
	end

    content = string.gsub(content, "lua.add_callback","LuaCEmbed_add_callback");
    value.set_value(content)
    value.hardware_modify()

end)

clib_tree.commit()
