
LuaCEmbedResponse * free_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);

    dtw.resource.free(resource);


    return  NULL;

}



LuaCEmbedResponse * resource_set_value(LuaCEmbedTable  *self,LuaCEmbed *args){
    Writeble  write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.set_binary(resource,write_obj.content, write_obj.size);
    return NULL;
}



LuaCEmbedResponse * resource_commit(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.commit(resource);
    return  NULL;

}

LuaCEmbedResponse * resource_destroy(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.destroy(resource);
    return  NULL;
}
LuaCEmbedResponse * unload_resurce(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.unload(resource);
    return  NULL;
}

LuaCEmbedResponse * lock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.lock(resource);
    return  NULL;
}

LuaCEmbedResponse * unlock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.unlock(resource);
    return  NULL;
}

LuaCEmbedTable *raw_create_resource(LuaCEmbed *args,DtwResource *resource){

    LuaCEmbedTable * self  = lua.tables.new_anonymous_table(args);
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
    if(!resource->child){
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