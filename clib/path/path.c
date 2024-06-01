
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
    return  lua.response.send_str_reference(dtw.path.get_full_name(self_path));
}

LuaCEmbedResponse *path_get_only_name(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return  lua.response.send_str_reference(dtw.path.get_name(self_path));
}

LuaCEmbedResponse *path_get_full_path(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return  lua.response.send_str_reference(dtw.path.get_path(self_path));
}

LuaCEmbedResponse *path_to_string(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return  lua.response.send_str_reference(dtw.path.get_path(self_path));
}

LuaCEmbedResponse *path_set_name(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_full_name = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);

    dtw.path.set_full_name(self_path,new_full_name);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_set_only_name(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_name = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);

    dtw.path.set_name(self_path,new_name);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_set_extension(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_extension = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);

    dtw.path.set_extension(self_path,new_extension);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_set_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_dir = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);

    dtw.path.set_dir(self_path,new_dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_set_path(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_path = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);

    dtw.path.set_path(self_path,new_path);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_replace_dirs(LuaCEmbedTable *self,LuaCEmbed *args){
    char *old_dir = lua.args.get_str(args,0);
    char *new_dir = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);

    dtw.path.replace_dirs(self_path,old_dir,new_dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_get_total_dirs(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    return  lua.response.send_long(dtw.path.get_total_dirs(self_path));
}

LuaCEmbedResponse *path_get_sub_dirs_from_index(LuaCEmbedTable *self,LuaCEmbed *args){
    long start_index = lua.args.get_long(args,0);
    long end_index = lua.args.get_long(args,1);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    char *sub_dirs = dtw.path.get_sub_dirs_from_index(self_path,start_index,end_index);
    return lua.response.send_str_reference(sub_dirs);;
}

LuaCEmbedResponse *path_insert_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args){
    long index = lua.args.get_long(args,0);
    char *dir = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.insert_dir_at_index(self_path,index,dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_remove_sub_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args){
    long start = lua.args.get_long(args,0);
    long end = lua.args.get_long(args,1);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.remove_sub_dirs_at_index(self_path,start,end);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_insert_dir_after(LuaCEmbedTable *self,LuaCEmbed *args){
    char *after_dir  = lua.args.get_str(args,0);
    char *dir = lua.args.get_str(args,1);

    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.insert_dir_after(self_path,after_dir,dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_insert_dir_before(LuaCEmbedTable *self,LuaCEmbed *args){
    char *before_dir  = lua.args.get_str(args,0);
    char *dir = lua.args.get_str(args,1);

    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.insert_dir_before(self_path,before_dir,dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_remove_sub_dirs_at(LuaCEmbedTable *self,LuaCEmbed *args){
    char *dirs_to_remove  = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
    dtw.path.remove_sub_dirs_at(self_path,dirs_to_remove);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *path_delete(LuaCEmbedTable *self,LuaCEmbed *args){

    bool its_a_ref = lua.tables.get_bool_prop(self,IS_A_REF);
    if(!its_a_ref){
        DtwPath *self_path = (DtwPath*)lua.tables.get_long_prop(self,PATH_POINTER);
        dtw.path.free(self_path);
    }

    return NULL;
}

LuaCEmbedTable *raw_create_path(LuaCEmbed *args,DtwPath *path){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);

    lua.tables.set_long_prop(self,PATH_POINTER,(long long )path);
    lua.tables.set_method(self,"add_end_dir",path_add_end_dir);
    lua.tables.set_method(self,"path_changed",path_changed);
    lua.tables.set_method(self,"add_start_dir",path_add_start_dir);
    lua.tables.set_method(self,"path_changed",path_changed);
    lua.tables.set_method(self,"get_dir",path_get_dir);
    lua.tables.set_method(self,"get_extension",path_get_extension);
    lua.tables.set_method(self,"get_name",path_get_name);
    lua.tables.set_method(self,"get_only_name",path_get_only_name);
    lua.tables.set_method(self,TO_STRING_METHOD,path_to_string);

    lua.tables.set_method(self,"set_extension",path_set_extension);
    lua.tables.set_method(self,"set_only_name",path_set_only_name);
    lua.tables.set_method(self,"set_name",path_set_name);
    lua.tables.set_method(self,"set_dir",path_set_dir);
    lua.tables.set_method(self,"set_path",path_set_path);
    lua.tables.set_method(self,"replace_dirs",path_replace_dirs);
    lua.tables.set_method(self,"get_total_dirs",path_get_total_dirs);
    lua.tables.set_method(self,"get_sub_dirs_from_index",path_get_total_dirs);
    lua.tables.set_method(self,"insert_dir_at_index",path_insert_dir_at_index);
    lua.tables.set_method(self,"remve_sub_dirs_at_index",path_remove_sub_dir_at_index);
    lua.tables.set_method(self,"insert_dir_after",path_insert_dir_after);
    lua.tables.set_method(self,"insert_dir_before",path_insert_dir_before);
    lua.tables.set_method(self,"remove_sub_dirs_at",path_remove_sub_dirs_at);
    lua.tables.set_method(self,DELETE_METHOD,path_delete);

    return self;
}

LuaCEmbedTable *create_path_reference(LuaCEmbed *args,DtwPath *path){
    LuaCEmbedTable *self =  raw_create_path(args,path);
    lua.tables.set_bool_prop(self,IS_A_REF,true);
    return self;
}


LuaCEmbedResponse *create_path(LuaCEmbed *args){
    char *content = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwPath *path = dtw.path.newPath(content);
    LuaCEmbedTable *self =  raw_create_path(args,path);
    lua.tables.set_bool_prop(self,IS_A_REF,false);
    return lua.response.send_table(self);
}

