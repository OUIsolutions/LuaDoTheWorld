


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

    if value.path.get_name() == "one.c" then

	    content = string.gsub(content,'#include "namespaces.h"',"");
	    content = string.gsub(content,'lua.newLuaLib',"newLuaCEmbedLib");
	    content = string.gsub(content,"lua.add_callback","LuaCEmbed_add_callback");
	    content = string.gsub(content,"lua.perform","LuaCembed_perform");
	    content = string.gsub(content,"lua %= newLuaCEmbedNamespace%(%)%;","");
        content = string.gsub(content,"dtw %= newDtwNamespace%(%)%;","");
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
	content = string.gsub(content,"lua.types.BOOL","LUA_CEMBED_BOOL");
	content = string.gsub(content,"lua.tables.get_size","LuaCEmbedTable_get_full_size");
	content = string.gsub(content,"lua.types.STRING","LUA_CEMBED_STRING");
	content = string.gsub(content,"lua.types.NUMBER","LUA_CEMBED_NUMBER");
	content = string.gsub(content,"lua.tables.append_string","LuaCEmbedTable_append_string");
	content = string.gsub(content,"lua.args.get_raw_str","LuaCEmbed_get_raw_str_arg");
	content = string.gsub(content,"lua.args.get_double","LuaCEmbed_get_double_arg");
	content = string.gsub(content,"lua.types.TABLE","LUA_CEMBED_TABLE");
	content = string.gsub(content,"lua.tables.append_long","LuaCEmbedTable_append_long");
	content = string.gsub(content,"lua.response.send_double","LuaCEmbed_send_double");
	content = string.gsub(content,"lua.tables.get_string_by_index","LuaCEmbedTable_get_string_by_index");
	content = string.gsub(content,"lua.convert_arg_code","LuaCembed_convert_arg_code");
	content = string.gsub(content,"lua.response.send_multi_return","LuaCEmbed_send_multi_return");


	content = string.gsub(content,"dtw.resource.get_schema_values","DtwResource_get_schema_values");
	content = string.gsub(content,"dtw.transaction.action.convert_action_to_string","DtwActionTransaction_convert_action_to_string");
	content = string.gsub(content,"dtw.transaction.commit","DtwTransaction_commit");
	content = string.gsub(content,"dtw.transaction.free","DtwTransaction_free");
	content = string.gsub(content,"dtw.transaction.newTransaction","newDtwTransaction");
	content = string.gsub(content,"dtw.transaction.dumps_transaction_to_json_file","DtwTransaction_dumps_to_json_file");


	content = string.gsub(content,"dtw.resource.dangerous_rename_schema_prop","DtwResource_dangerous_rename_schema_prop");
    content = string.gsub(content,"dtw.resource.dangerous_remove_schema_prop","DtwResource_dangerous_remove_schema_prop");
	content = string.gsub(content,"dtw.resource.error","DtwResource_error");
	content = string.gsub(content,"dtw.resource.free","DtwResource_free");
	content = string.gsub(content,"dtw.resource.set_binary","DtwResource_set_binary");
	content = string.gsub(content,"dtw.resource.commit","DtwResource_commit");
	content = string.gsub(content,"dtw.resource.destroy","DtwResource_destroy");

	content = string.gsub(content,"dtw.resource.unload","DtwResource_unload");
	content = string.gsub(content,"dtw.resource.sub_resources","DtwResource_sub_resources");
	content = string.gsub(content,"dtw.resource.sub_resource","DtwResource_sub_resource");

	content = string.gsub(content,"dtw.resource.sub_resource_next","DtwResource_sub_resource_next");
	content = string.gsub(content,"dtw.resource.sub_resource_now","DtwResource_sub_resource_now");
	content = string.gsub(content,"dtw.resource.sub_resource_now_in_unix","DtwResource_sub_resource_now_in_unix");
	content = string.gsub(content,"dtw.transaction.dumps_transaction_to_json","DtwTransaction_dumps_to_json");
	content = string.gsub(content,"dtw.transaction.newTransaction_from_json","newDtwTransaction_from_json");
	content = string.gsub(content,"dtw.transaction.write_any","DtwTransaction_write_any");
	content = string.gsub(content,"dtw.transaction.delete_any","DtwTransaction_delete_any");
	content = string.gsub(content,"dtw.transaction.copy_any","DtwTransaction_copy_any");
	content = string.gsub(content,"dtw.transaction.move_any","DtwTransaction_move_any");

	content = string.gsub(content,"dtw.tree.part.load_content_from_hardware","DtwTreePart_load_content_from_hardware");
	content = string.gsub(content,"dtw.tree.loads_json_tree","DtwTree_loads_json_tree");
	content = string.gsub(content,"dtw.tree.part.set_any_content","DtwTreePart_set_any_content");
	content = string.gsub(content,"dtw.tree.part.hardware_remove","DtwTreePart_hardware_remove");
	content = string.gsub(content,"dtw.tree.part.hardware_write","DtwTreePart_hardware_write");
	content = string.gsub(content,"dtw.tree.part.hardware_modify","DtwTreePart_hardware_modify");
	content = string.gsub(content,"dtw.tree.part.free_content","DtwTreePart_free_content");
	content = string.gsub(content,"lua.tables.set_sub_table_prop","LuaCEmbedTable_set_sub_table_prop");
	content = string.gsub(content,"dtw.tree.hardware_commit_tree","DtwTree_hardware_commit_tree");
	content = string.gsub(content,"dtw.tree.insecure_hardware_write_tree","DtwTree_insecure_hardware_write_tree");
	content = string.gsub(content,"dtw.tree.insecure_hardware_remove_tree","DtwTree_insecure_hardware_remove_tree");
	content = string.gsub(content,"dtw.tree.add_tree_from_hardware","DtwTree_add_tree_from_hardware");
	content = string.gsub(content,"lua.tables.get_bool_by_index","LuaCEmbedTable_get_bool_by_index");
	content = string.gsub(content,"lua.tables.append_evaluation","LuaCEmbedTable_append_evaluation");
	content = string.gsub(content,"dtw.tree.free","DtwTree_free");
	content = string.gsub(content,"dtw.tree.add_tree_part_getting_owenership","DtwTree_add_tree_part_getting_onwership");

	content = string.gsub(content,"dtw.load_any_content","dtw_load_any_content");
	content = string.gsub(content,"dtw.tree.find_tree_part_by_path","DtwTree_find_tree_part_by_path");
	content = string.gsub(content,"dtw.tree.newTree","newDtwTree");
	content = string.gsub(content,"dtw.load_string_file_content","dtw_load_string_file_content");
	content = string.gsub(content,"dtw.tree.dumps_json_tree","DtwTree_dumps_tree_json");
	content = string.gsub(content,"dtw.tree.dumps_json_tree_to_file","DtwTree_dumps_tree_json_to_file");
	content = string.gsub(content,"dtw.tree.part.newPart","newDtwTreePart");
	content = string.gsub(content,"dtw.tree.part.newPartLoading","newDtwTreePartLoading");
	content = string.gsub(content,"dtw.tree.part.newPartEmpty","newDtwTreePartEmpty");
	content = string.gsub(content,"dtw.tree.find_tree_part_by_name","DtwTree_find_tree_part_by_name");
	content = string.gsub(content,"dtw.tree.find_tree_part_by_path","DtwTree_find_tree_part_by_path");
	content = string.gsub(content,"dtw.path.changed","DtwPath_changed");
	content = string.gsub(content,"dtw.path.add_start_dir","DtwPath_add_start_dir");
	content = string.gsub(content,"dtw.path.add_end_dir","DtwPath_add_end_dir");
	content = string.gsub(content,"dtw.path.get_dir","DtwPath_get_dir");
	content = string.gsub(content,"dtw.path.get_extension","DtwPath_get_extension");
	content = string.gsub(content,"dtw.path.get_full_name","DtwPath_get_full_name");

	content = string.gsub(content,"dtw.path.get_name","DtwPath_get_name");
	content = string.gsub(content,"dtw.path.get_path","DtwPath_get_path");
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
	content = string.gsub(content,"dtw.generate_sha_from_file","dtw_generate_sha_from_file");
	content = string.gsub(content,"dtw.string_array.sort","DtwStringArray_sort");
	content = string.gsub(content,"dtw.write_any_content","dtw_write_any_content");

	content = string.gsub(content,"dtw.base64_encode","dtw_base64_encode");
	content = string.gsub(content,"dtw.base64_decode","dtw_base64_decode");
	content = string.gsub(content,"dtw.convert_binary_file_to_base64","dtw_convert_binary_file_to_base64");
	content = string.gsub(content,"dtw.list_all_recursively","dtw_list_all_recursively");
	content = string.gsub(content,"dtw.list_dirs_recursively","dtw_list_dirs_recursively");
	content = string.gsub(content,"dtw.list_files_recursively","dtw_list_files_recursively");
	content = string.gsub(content,"dtw.list_all","dtw_list_all");
	content = string.gsub(content,"dtw.list_dirs","dtw_list_dirs");
	content = string.gsub(content,"dtw.list_files","dtw_list_files");
	content = string.gsub(content,"dtw.remove_any","dtw_remove_any");
	content = string.gsub(content,"dtw.move_any","dtw_move_any");
	content = string.gsub(content,"dtw.copy_any","dtw_copy_any");
	content = string.gsub(content,"dtw.write_string_file_content","dtw_write_string_file_content");


	content = string.gsub(content,"dtw.resource.get_error_message","DtwResource_get_error_message");
	content = string.gsub(content,"dtw.tree.json_error.validate_json_tree_by_content","DtwJsonTreeError_validate_json_tree_by_content");
	content = string.gsub(content,"dtw.hash.newHash","newDtwHash");
	content = string.gsub(content,"dtw.generate_sha_from_any","dtw_generate_sha_from_any");
	content = string.gsub(content,"dtw.hash.digest_file","DtwHash_digest_file");
	content = string.gsub(content,"dtw.hash.digest_folder_by_content","DtwHash_digest_folder_by_content");
	content = string.gsub(content,"dtw.hash.digest_folder_by_last_modification","DtwHash_digest_folder_by_last_modification");
	content = string.gsub(content,"dtw.hash.free","DtwHash_free");
	content = string.gsub(content,"dtw.tree.json_error.free","DtwJsonTreeError_free");
	content = string.gsub(content,"dtw.resource.clear_errors","DtwResource_clear_errors");
	content = string.gsub(content,"dtw.resource.rename","DtwResource_rename");
	content = string.gsub(content,"dtw.resource.find_by_name_id","DtwResource_find_by_name_id");
	content = string.gsub(content,"dtw.resource.find_by_primary_key_with_binary","DtwResource_find_by_primary_key_with_binary");
	content = string.gsub(content,"dtw.resource.new_schema_insertion","DtwResource_new_schema_insertion");
	content = string.gsub(content,"dtw.resource.get_bool","DtwResource_get_bool");
	content = string.gsub(content,"dtw.resource.type","DtwResource_type");
	content = string.gsub(content,"dtw.resource.get_string","DtwResource_get_string");
	content = string.gsub(content,"dtw.schema.sub_schema","DtwSchema_new_subSchema");
	content = string.gsub(content,"dtw.schema.add_primary_key","DtwSchema_add_primary_key");
	content = string.gsub(content,"dtw.hash.digest_any","DtwHash_digest_any");
	content = string.gsub(content,"dtw.string_array.free","DtwStringArray_free");
	content = string.gsub(content,"dtw.resource.get_double","DtwResource_get_double");
	content = string.gsub(content,"dtw.resource.get_any","DtwResource_get_any");

	--print(content)
	value.set_value(content)
	value.hardware_modify()

end)


clib_tree.commit()

os.execute("gcc -Wall -shared -fpic -o teste.so clib2/one.c")
