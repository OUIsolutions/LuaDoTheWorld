
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

LuaCEmbedResponse * resource_sub_resource_next(LuaCEmbedTable  *self,LuaCEmbed *args){
    const char *src = "";
    if(lua.args.size(args) > 0){
        src  = lua.args.get_str(args,0);
    }
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }

    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = dtw.resource.sub_resource_next(resource,src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return lua.response.send_table(sub);
}

LuaCEmbedResponse * resource_sub_resource_now(LuaCEmbedTable  *self,LuaCEmbed *args){
    const char *src = "";
    if(lua.args.size(args) > 0){
        src  = lua.args.get_str(args,0);
    }
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }

    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = dtw.resource.sub_resource_now(resource,src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return lua.response.send_table(sub);
}

LuaCEmbedResponse * resource_sub_resource_now_in_unix(LuaCEmbedTable  *self,LuaCEmbed *args){
    const char *src = "";
    if(lua.args.size(args) > 0){
        src  = lua.args.get_str(args,0);
    }
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }

    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = dtw.resource.sub_resource_now_in_unix(resource,src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return lua.response.send_table(sub);
}

