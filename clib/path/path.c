
LuaCEmbedResponse *path_changed(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return lua.response.send_bool(dtw.path.changed(self_path));
}


LuaCEmbedResponse *add_start_dir_to_path(LuaCEmbedTable *self,LuaCEmbed *args){
        
}

LuaCEmbedResponse *add_end_dir_to_path(LuaCEmbedTable *self,LuaCEmbed *args){
    char *end_dir = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.add_end_dir(self_path,end_dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *raw_create_path(LuaCEmbed *args,DtwPath *path){
    LuaCEmbedTable *table = lua.tables.new_anonymous_table(args);
    dtw.path.
    lua.tables.set_long_prop(table,PATH_POINTER,(long long )path);
    lua.tables.set_method(table,"add_end_dir",add_end_dir_to_path);
    lua.tables.set_method(table,"add_start_dir",add_start_dir_to_path);
    lua.tables.set_method(table,"path_changed",path_changed);
    return lua.response.send_table(table);
}

LuaCEmbedResponse *create_path_reference(LuaCEmbed *args,DtwPath *path);


LuaCEmbedResponse *create_path(LuaCEmbed *args);

