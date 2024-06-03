


local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.copy_any_overwriting("clib","clib2")
local clib_tree = dtw.newTree_from_hardware("clib2")

clib_tree.each(function (value)
	local content = value.get_value()

	if content == nil or dtw.is_blob(value)  then
		return
	end

    content = string.gsub(content, "lua.add_callback","LuaCEmbed_add_callback");

    
end)
