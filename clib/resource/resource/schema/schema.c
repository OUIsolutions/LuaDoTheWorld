//
// Created by mateusmoutinho on 22/05/24.
//
LuaCEmbedResponse  * Resource_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResource  *created = dtw.resource.new_schema_insertion(resource);
    LuaCEmbedTable  *sub = raw_create_resource(args,created);
    return lua.response.send_table(sub);
}

LuaCEmbedResponse * resource_schema_each(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = dtw.resource.get_schema_values(resource);

    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_callback,sub);
        lua.args.run_lambda(args,0,args_to_callback,0);
    }

    return NULL;
}

LuaCEmbedResponse  * get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args){
    char *key = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    Writeble  write_obj = create_writeble(args,1);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);

    DtwResource *founded = dtw.resource.find_by_primary_key_with_binary(resource,key,write_obj.content,write_obj.size);
    if(!founded){
        return NULL;
    }
    LuaCEmbedTable  *sub = raw_create_resource(args,founded);
    return lua.response.send_table(sub);
}


LuaCEmbedResponse  * get_resource_by_name_id(LuaCEmbedTable *self, LuaCEmbed *args){
    char *name_id = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }


    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResource *founded = dtw.resource.find_by_name_id(resource,name_id);

    if(!founded){
        return NULL;
    }
    
    LuaCEmbedTable  *sub = raw_create_resource(args,founded);
    return lua.response.send_table(sub);
}

LuaCEmbedResponse  * dangerous_rename_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args){
    char *key = lua.args.get_str(args,0);
    char *new_name = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }


    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.dangerous_rename_schema_prop(resource,key,new_name);
    return lua.response.send_table(self);
}

LuaCEmbedResponse  * dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args){
    char *key_to_remove = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }

    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    dtw.resource.dangerous_remove_schema_prop(resource,key_to_remove);
    return lua.response.send_table(self);
}

LuaCEmbedResponse  * Resource_new_schema(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwSchema  *schema = dtw.resource.newSchema(resource);
    LuaCEmbedTable *created_table = raw_create_schema(args,schema);
    return lua.response.send_table(created_table);
}

