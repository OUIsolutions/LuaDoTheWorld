
LuaCEmbedResponse * private_resource_sub_resource_raw(LuaCEmbedTable  *self, LuaCEmbed *args,const char *src){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = dtw.resource.sub_resource(resource,"%s",src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return lua.response.send_table(sub);
}

LuaCEmbedResponse * resource_sub_resource_index(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);

    int type = lua.args.get_type(args,1);
    if(type == lua.types.NUMBER){
        long  i = lua.args.get_long(args,1)-1;
        DtwResourceArray  *elements = dtw.resource.sub_resources(resource);

        if(i >=elements->size || i  < 0){
            return NULL;
        }
        DtwResource *current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        return lua.response.send_table(sub);
    }

    char *src = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    return private_resource_sub_resource_raw(self,args,src);
}
LuaCEmbedResponse * resource_sub_resource_normal(LuaCEmbedTable  *self, LuaCEmbed *args){

    int type = lua.args.get_type(args,0);
    if(type == lua.types.NUMBER){
        long  i = lua.args.get_long(args,1)-1;
        char src[20] = {0};
        sprintf(src,"%ld",i);
        return private_resource_sub_resource_raw(self,args,src);
    }

    char *src = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    return private_resource_sub_resource_raw(self,args,src);
}


LuaCEmbedResponse * resource_sub_resource_method(LuaCEmbedTable  *self, LuaCEmbed *args){
    char *src = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    return private_resource_sub_resource_raw(self,args,src);
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

