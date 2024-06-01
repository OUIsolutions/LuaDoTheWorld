
LuaCEmbedResponse *path_changed(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return lua.response.send_bool(dtw.path.changed(self_path));
}


LuaCEmbedResponse *path_add_start_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    char *start_dir = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.add_start_dir(self_path,start_dir);
    return lua.response.send_table(self);
}


LuaCEmbedResponse *path_add_end_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    char *end_dir = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.add_end_dir(self_path,end_dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_get_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return  lua.response.send_str_reference(dtw.path.get_dir(self_path));
}
LuaCEmbedResponse *path_get_extension(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return  lua.response.send_str_reference(dtw.path.get_extension(self_path));
}

LuaCEmbedResponse *path_get_name(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return  lua.response.send_str_reference(dtw.path.get_name(self_path));
}

LuaCEmbedResponse *path_get_only_name(LuaCEmbedTable *self,LuaCEmbed *args){

}

LuaCEmbedResponse *path_get_full_path(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_to_string(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_only_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_extension(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_dir(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_path(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_replace_dirs(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_get_total_dirs(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_get_sub_dirs_from_index(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_insert_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_remove_sub_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_insert_dir_after(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_insert_dir_before(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_remove_sub_dirs_at(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_delete(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *raw_create_path(LuaCEmbed *args,DtwPath *path){
    LuaCEmbedTable *table = lua.tables.new_anonymous_table(args);

    lua.tables.set_long_prop(table,PATH_POINTER,(long long )path);
    lua.tables.set_method(table,"add_end_dir",path_add_end_dir);
    lua.tables.set_method(table,"path_changed",path_changed);
    lua.tables.set_method(table,"add_start_dir",path_add_start_dir);
    lua.tables.set_method(table,"path_changed",path_changed);
    lua.tables.set_method(table,"get_dir",path_get_dir);
    lua.tables.set_method(table,"get_extension",path_get_extension);
    lua.tables.set_method(table,"get_name",path_get_name);
    lua.tables.set_method(table,"get_only_name",path_get_only_name);
    lua.tables.set_method(table,TO_STRING_METHOD,path_to_string);

    lua.tables.set_method(table,"set_extension",path_set_extension);
    lua.tables.set_method(table,"set_only_name",path_set_only_name);
    lua.tables.set_method(table,"set_name",path_set_name);
    lua.tables.set_method(table,"set_dir",path_set_dir);
    lua.tables.set_method(table,"set_path",path_set_path);
    lua.tables.set_method(table,"replace_dirs",path_replace_dirs);
    lua.tables.set_method(table,"get_total_dirs",path_get_total_dirs);
    lua.tables.set_method(table,"get_sub_dirs_from_index",path_get_total_dirs);
    lua.tables.set_method(table,"insert_dir_at_index",path_insert_dir_at_index);
    lua.tables.set_method(table,"remve_sub_dirs_at_index",path_remove_sub_dir_at_index);
    lua.tables.set_method(table,"insert_dir_after",path_insert_dir_after);
    lua.tables.set_method(table,"insert_dir_before",path_insert_dir_before);
    lua.tables.set_method(table,"remove_sub_dirs_at",path_remove_sub_dirs_at);
    lua.tables.set_method(table,DELETE_METHOD,path_delete);

    return lua.response.send_table(table);
}

LuaCEmbedResponse *create_path_reference(LuaCEmbed *args,DtwPath *path);


LuaCEmbedResponse *create_path(LuaCEmbed *args);

