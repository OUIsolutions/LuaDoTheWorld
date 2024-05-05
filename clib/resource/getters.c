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