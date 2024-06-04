


local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.copy_any_overwriting("clib","clib2")

local clib_tree = dtw.newTree_from_hardware("clib2")

clib_tree.get_tree_part_by_name("namespaces.h").hardware_remove()

clib_tree.each(function (value)

	local content = value.get_value()
	if content == nil or value.is_blob() then
		return
	end
	if value.path.get_name() == "namespaces.h" then
		return
	end

    if value.path.get_name() == "main.c" then
	    content = string.gsub(content,"lua = newLuaCEmbedNamespace();","");
	    content = string.gsub(content,'dtw = newDtwNamespace();',"");
	    content = string.gsub(content,'#include "namespaces.h"',"");
	    content = string.gsub(content,'lua.newLuaLib',"newLuaCEmbedLib");
	    content = string.gsub(content,"lua.add_callback","LuaCEmbed_add_callback");
	    content = string.gsub(content,"lua.perform","LuaCembed_perform");

    	value.set_value(content)
    	value.hardware_modify()
        return
    end
	content = string.gsub(content,"lua.add_callback","LuaCEmbed_add_callback");
	content = string.gsub(content,"lua.args.get_long","LuaCEmbed_get_long_arg");
	content = string.gsub(content,"lua.args.get_str","LuaCEmbed_get_str_arg");
	content = string.gsub(content,"lua.args.get_type","LuaCEmbed_get_arg_type");
	content = string.gsub(content,"lua.has_errors","LuaCEmbed_has_errors");
	content = string.gsub(content,"lua.get_error_message","LuaCEmbed_get_error_message");
	content = string.gsub(content,"lua.response.send_error","LuaCEmbed_send_error");
	content = string.gsub(content,"lua.response.send_str","LuaCEmbed_send_str");
	content = string.gsub(content,"lua.response.send_long","LuaCEmbed_send_long");
	content = string.gsub(content,"lua.tables.append_table","LuaCEmbedTable_append_table");
	content = string.gsub(content,"lua.response.send_raw_string","LuaCEmbed_send_raw_string");
	content = string.gsub(content,"lua.tables.get_long_prop","LuaCembedTable_get_long_prop");
	content = string.gsub(content,"lua.tables.set_long_prop","LuaCEmbedTable_set_long_prop");
	content = string.gsub(content,"lua.tables.get_bool_prop","LuaCembedTable_get_bool_prop");
	content = string.gsub(content,"lua.response.send_table","LuaCEmbed_send_table");
	content = string.gsub(content,"lua.tables.set_bool_prop","LuaCEmbedTable_set_bool_prop");
	content = string.gsub(content,"lua.tables.new_anonymous_table","LuaCembed_new_anonymous_table");
	content = string.gsub(content,"lua.tables.new_anonymous_table","LuaCembed_new_anonymous_table");
	content = string.gsub(content,"dtw.entity_type","dtw_entity_type");
	content = string.gsub(content,"lua.args.size","LuaCEmbed_get_total_args");
	content = string.gsub(content,"lua.types.NILL","LUA_CEMBED_NIL");
	content = string.gsub(content,"lua.tables.set_method","LuaCEmbedTable_set_method");
	content = string.gsub(content,"lua.tables.get_type_prop","LuaCEmbedTable_get_type_prop");
	content = string.gsub(content,"lua.args.run_lambda","LuaCEmbed_run_args_lambda");
	content = string.gsub(content,"lua.response.send_bool","LuaCEmbed_send_bool");
	content = string.gsub(content,"lua.args.get_bool","LuaCEmbed_get_bool_arg");
	content = string.gsub(content,"lua.tables.get_type_by_index","LuaCEmbedTable_get_type_by_index");
	content = string.gsub(content,"lua.args.get_table","LuaCEmbed_get_arg_table");



	content = string.gsub(content,"dtw.path.set_full_name","DtwPath_set_full_name");
	content = string.gsub(content,"dtw.path.set_name","DtwPath_set_name");
	content = string.gsub(content,"dtw.path.set_extension","DtwPath_set_extension");
	content = string.gsub(content,"dtw.path.set_dir","DtwPath_set_dir");
	content = string.gsub(content,"dtw.path.set_path","DtwPath_set_path");
	content = string.gsub(content,"dtw.path.replace_dirs","DtwPath_replace_dirs");
	content = string.gsub(content,"dtw.path.get_total_dirs","DtwPath_get_total_dirs");
	content = string.gsub(content,"dtw.path.get_sub_dirs_from_index","DtwPath_get_sub_dirs_from_index");
	content = string.gsub(content,"dtw.path.insert_dir_at_index","DtwPath_insert_dir_at_index");
	content = string.gsub(content,"dtw.path.remove_sub_dirs_at_index","DtwPath_remove_sub_dirs_at_index");
	content = string.gsub(content,"dtw.path.insert_dir_after","DtwPath_insert_dir_after");
	content = string.gsub(content,"dtw.path.insert_dir_before","DtwPath_insert_dir_before");
	content = string.gsub(content,"dtw.path.remove_sub_dirs_at","DtwPath_remove_sub_dirs_at");
	content = string.gsub(content,"dtw.path.free","DtwPath_free");
	content = string.gsub(content,"dtw.path.newPath","newDtwPath");
	content = string.gsub(content,"dtw.resource.load","DtwResource_load");
	content = string.gsub(content,"dtw.resource.newSchema","DtwResource_newSchema");
	content = string.gsub(content,"dtw.resource.unlock","DtwResource_unlock");
	content = string.gsub(content,"dtw.resource.lock","DtwResource_lock");
	content = string.gsub(content,"dtw.complex_entity_type","dtw_complex_entity_type");
	--print(content)
	value.set_value(content)
	value.hardware_modify()

end)


clib_tree.commit()

os.execute("gcc -Wall -shared -fpic -o teste.so clib2/main.c")
