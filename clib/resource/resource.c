
LuaCEmbedResponse * delete_resource(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
}

LuaCEmbedResponse * resource_to_string(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    char *value = dtw.resource.get_string(resource);
    if(dtw.resource.error(resource)){
        char *error_message = dtw.resource.get_error_message(resource);
        LuaCEmbedResponse *response = lua.response.send_error(error_message);
        dtw.resource.clear_errors(resource);
        return response;
    }
    return lua.response.send_str(value);
}


LuaCEmbedResponse * resource_to_number(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    double value = dtw.resource.get_double(resource);
    if(dtw.resource.error(resource)){
        char *error_message = dtw.resource.get_error_message(resource);
        LuaCEmbedResponse *response = lua.response.send_error(error_message);
        dtw.resource.clear_errors(resource);
        return response;
    }
    return lua.response.send_double(value);
}

LuaCEmbedResponse * resource_value(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    int type = dtw.resource.type(resource);

    if(type == DTW_FOLDER_TYPE || type == DTW_NOT_FOUND){
        return NULL;
    }
    if(type == DTW_COMPLEX_DOUBLE_TYPE || type == DTW_COMPLEX_LONG_TYPE){
        double value = dtw.resource.get_double(resource);
        return lua.response.send_double(value);
    }
    if(type == DTW_COMPLEX_STRING_TYPE){
        char *value = dtw.resource.get_string(resource);
        return lua.response.send_str(value);
    }

    if(type == DTW_COMPLEX_BOOL_TYPE){
        bool value= dtw.resource.get_bool(resource);
        return lua.response.send_bool(value);
    }

    if(type == DTW_COMPLEX_BINARY){
        long size;
        bool is_binary;
        unsigned  char *content =  dtw.resource.get_any(resource,&size,&is_binary);
        LuaCEmbedTable *bytes = create_bytes_ref(args,content,size);
        return lua.response.send_table(bytes);
    }
    return NULL;
}


LuaCEmbedResponse * resource_to_boolean(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
   bool value = dtw.resource.get_bool(resource);
    if(dtw.resource.error(resource)){
        char *error_message = dtw.resource.get_error_message(resource);
        LuaCEmbedResponse *response = lua.response.send_error(error_message);
        dtw.resource.clear_errors(resource);
        return response;
    }
    return lua.response.send_bool(value);
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


LuaCEmbedResponse * resource_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args){
    char *src = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = dtw.resource.sub_resource(resource,"%s",src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return lua.response.send_table(sub);
}


LuaCEmbedTable *raw_create_resource(LuaCEmbed *args,DtwResource *resource){

    LuaCEmbedTable * self  = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,RESOURCE_POINTER,(long)resource);
    lua.tables.set_method(self,TO_STRING_METHOD,resource_to_string);
    lua.tables.set_method(self,TO_NUMBER_METHOD,resource_to_number);
    lua.tables.set_method(self,TO_BOOLEAN_METHOD,resource_to_boolean);
    lua.tables.set_method(self,GET_VALUE_METHOD,resource_value);
    lua.tables.set_method(self,INDEX_METHD,resource_sub_resource);
    lua.tables.set_method(self,SET_VALUE_METHOD,resource_set_value);
    
    bool is_root = !resource->child;

    if(is_root){
        lua.tables.set_method(self,DELETE_METHOD,delete_resource);
    }

    return self;
}



LuaCEmbedResponse * createResource(LuaCEmbed *args){
    char *folder = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwResource *resource = new_DtwResource(folder);
    LuaCEmbedTable  *self = raw_create_resource(args,resource);
    return lua.response.send_table(self);

}