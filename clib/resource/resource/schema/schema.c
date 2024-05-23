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

LuaCEmbedResponse * schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(resource->values_resource);
    LuaCEmbedTable *response = lua.tables.new_anonymous_table(args);
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        lua.tables.append_table(response,sub);
    }
    return lua.response.send_table(response);
}
LuaCEmbedResponse * schema_find_resource(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(resource->values_resource);
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_callback,sub);
        LuaCEmbedTable  *user_response = lua.args.run_lambda(args,0,args_to_callback,1);

        if(lua.has_errors(args)){
            char *error = lua.get_error_message(args);
            return lua.response.send_error(error);
        }

        bool possible_return = lua.tables.get_bool_by_index(user_response,0);
        if(possible_return){
            return lua.response.send_table(sub);
        }
    }

    return NULL;
}



LuaCEmbedResponse * schema_count_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(resource->values_resource);
    long size = 0;
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_callback,sub);
        LuaCEmbedTable  *user_response = lua.args.run_lambda(args,0,args_to_callback,1);

        if(lua.has_errors(args)){
            char *error = lua.get_error_message(args);
            return lua.response.send_error(error);
        }

        bool possible_return = lua.tables.get_bool_by_index(user_response,0);
        if(possible_return){
            size+=1;
        }
    }

    return lua.response.send_long(size);
}

LuaCEmbedResponse * schema_map_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(resource->values_resource);
    LuaCEmbedTable *response = lua.tables.new_anonymous_table(args);

    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_callback,sub);
        LuaCEmbedTable  *user_response = lua.args.run_lambda(args,0,args_to_callback,1);

        if(lua.has_errors(args)){
            char *error = lua.get_error_message(args);
            return lua.response.send_error(error);
        }
        long size = lua.tables.get_size(user_response);
        if(size ==1){
            lua.tables.append_evaluation(response,"%s[1]",user_response->global_name);
        }


    }

    return lua.response.send_table(response);
}

