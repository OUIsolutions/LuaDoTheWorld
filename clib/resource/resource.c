
LuaCEmbedResponse * free_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);

    dtw.resource.free(resource);


    return  NULL;

}

LuaCEmbedResponse * resource_foreach(LuaCEmbedTable  *self,LuaCEmbed *args) {


    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(resource);

    for(int i =0; i < elements->size; i++) {
        DtwResource *current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable *args_to_callback = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_callback,sub);
        lua.args.run_lambda(args,0,args_to_callback,0);

    }
    return lua.response.send_table(self);

}

LuaCEmbedResponse * resource_set_value(LuaCEmbedTable  *self,LuaCEmbed *args){
    Writeble  write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.set_binary(resource,write_obj.content, write_obj.size);
    return  lua.response.send_table(self);
}



LuaCEmbedResponse * resource_commit(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.commit(resource);
    return  lua.response.send_table(self);

}

LuaCEmbedResponse * resource_destroy(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.destroy(resource);
    return  lua.response.send_table(self);
}
LuaCEmbedResponse * unload_resurce(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.unload(resource);
    return  lua.response.send_table(self);
}

LuaCEmbedResponse * lock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.lock(resource);
    return  lua.response.send_table(self);
}

LuaCEmbedResponse * unlock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.unlock(resource);
    return  NULL;
}
LuaCEmbedResponse * resource_sub_schema(LuaCEmbedTable  *self,LuaCEmbed *args){
    char *src = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwSchema *schema = dtw.resource.sub_schema(resource,src);
    LuaCEmbedTable  *created = raw_create_schema(args,schema);
    return lua.response.send_table(created);

}

LuaCEmbedResponse * resource_set_value_in_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args){

    char *folder = lua.args.get_str(args,0);
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }

    Writeble  write_obj = create_writeble(args,1);
    if(write_obj.error){
        return write_obj.error;
    }

    DtwResource *values = dtw.resource.sub_resource(resource,folder);
    dtw.resource.set_binary(values,write_obj.content,write_obj.size);
    return lua.response.send_table(self);

}



LuaCEmbedTable *raw_create_resource(LuaCEmbed *args,DtwResource *resource){

    LuaCEmbedTable * self  = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,DTW_TYPE,DTW_RESOURCE_TYPE);

    lua.tables.set_long_prop(self,RESOURCE_POINTER,(long)resource);
    lua.tables.set_method(self,TO_STRING_METHOD,resource_to_string);
    lua.tables.set_method(self,TO_NUMBER_METHOD,resource_to_number);
    lua.tables.set_method(self,TO_BOOLEAN_METHOD,resource_to_boolean);
    lua.tables.set_method(self,GET_VALUE_METHOD,resource_value);
    lua.tables.set_method(self, INDEX_METHOD, resource_sub_resource_index);
    lua.tables.set_method(self, SUB_RESOURCE_METHOD, resource_sub_resource_method);

    lua.tables.set_method(self, SUB_RESOURCE_NEXT_METHOD, resource_sub_resource_next);
    lua.tables.set_method(self, SUB_RESOURCE_NOW_METHOD, resource_sub_resource_now);
    lua.tables.set_method(self, SUB_RESOURCE_NOW_IN_UNIX, resource_sub_resource_now_in_unix);
    lua.tables.set_method(self,LOCK_METHOD,lock_resource);
    lua.tables.set_method(self,UNLOCK_METHOD,unlock_resource);
    lua.tables.set_method(self,UNLOAD_METHOD,unload_resurce);

    lua.tables.set_method(self,SET_VALUE_METHOD,resource_set_value);
    lua.tables.set_method(self,COMMIT_METHOD,resource_commit);
    lua.tables.set_method(self,DESTROY_METHOD,resource_destroy);

    lua.tables.set_method(self, GET_NAME_METHOD, resource_get_name);
    lua.tables.set_method(self, GET_PATH_METHOD, resource_get_path);
    lua.tables.set_method(self, GET_EXTENSION, resource_get_extension);
    lua.tables.set_method(self, GET_DIR_METHOD, resource_get_dir);
    lua.tables.set_method(self, GET_NAME_WITHOUT_EXTENSION, resource_get_name_without_extension);
    lua.tables.set_method(self, SET_EXTENSION_METHOD,resource_set_extension);
    lua.tables.set_method(self,LIST_METHOD,resource_list);
    lua.tables.set_method(self,EACH_METHOD,resource_foreach);
    lua.tables.set_method(self, SUB_SCHEMA_METHOD, resource_sub_schema);
    lua.tables.set_method(self, SET_VALUE_IN_SUB_RESOURCE_METHOD, resource_set_value_in_sub_resource);
    lua.tables.set_method(self,GET_VALUE_FROM_SUB_RESOURCE_METHOD,resource_value_from_sub_resource);

    if(!resource->mother){
        lua.tables.set_method(self, DELETE_METHOD, free_resource);
    }

    return self;
}



LuaCEmbedResponse * create_resource(LuaCEmbed *args){
    char *folder = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwResource *resource = new_DtwResource(folder);

    LuaCEmbedTable  *self = raw_create_resource(args,resource);
    return lua.response.send_table(self);

}