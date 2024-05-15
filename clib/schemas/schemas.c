

LuaCEmbedResponse  * add_schema_primary_keys(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    int arg_type = lua.args.get_type(args,0);
    if(arg_type == lua.types.STRING){
        char *value = lua.args.get_str(args,0);
        dtw.schema.add_primary_key(schema,value);
        return lua.response.send_table(self);
    }

    if(arg_type != lua.types.TABLE){
        return lua.response.send_error(ARGUMENT_NOT_IN_STRING_OR_STRING_ARRAY);
    }

    LuaCEmbedTable *string_array = lua.args.get_table(args,0);
    long size = lua.tables.get_size(string_array);
    for(int i = 0; i < size;i++){
        int current_type = lua.tables.get_type_by_index(string_array,i);
        if(current_type != lua.types.STRING){
            return lua.response.send_error(ARGUMENT_NOT_IN_STRING_OR_STRING_ARRAY);
        }
    }

    for(int i = 0; i < size;i++){
        char *current_value = lua.tables.get_string_by_index(string_array,i);
        dtw.schema.add_primary_key(schema,current_value);
    }
    return lua.response.send_table(self);
}

LuaCEmbedResponse  * schema_new_insertion(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResource  *created = dtw.schema.new_insertion(schema);
    LuaCEmbedTable  *sub = raw_create_resource(args,created);
    return lua.response.send_table(sub);
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
    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);

    DtwResource *founded = dtw.schema.find_by_primary_key_with_binary(schema,key,write_obj.content,write_obj.size);
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


    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResource *founded = dtw.schema.find_by_nameID(schema,name_id);

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


    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    dtw.schema.dangerous_rename_prop(schema,key,new_name);
    return lua.response.send_table(self);
}

LuaCEmbedResponse  * dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args){
    char *key_to_remove = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }


    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    dtw.schema.dangerous_remove_prop(schema,key_to_remove);
    return lua.response.send_table(self);
}

LuaCEmbedResponse  * commit_schema(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    dtw.schema.commit(schema);
    return lua.response.send_table(self);
}

LuaCEmbedResponse  * delete_schema(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    dtw.schema.free(schema);
    return lua.response.send_table(self);

}

LuaCEmbedResponse * schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(schema->values_resource);
    LuaCEmbedTable *response = lua.tables.new_anonymous_table(args);
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        lua.tables.append_table(response,sub);
    }
    return lua.response.send_table(response);
}


LuaCEmbedResponse * schema_find_resource(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(schema->values_resource);
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
    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(schema->values_resource);
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

LuaCEmbedResponse * schema_each(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(schema->values_resource);
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_callback,sub);
        lua.args.run_lambda(args,0,args_to_callback,0);
    }

    return NULL;
}
LuaCEmbedResponse * schema_map_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResourceArray  *elements = dtw.resource.sub_resources(schema->values_resource);
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
        int size = lua.tables.get_size(user_response);
        if(size ==1){
            lua.tables.append_evaluation(response,"%s[0]",user_response->global_name);
        }


    }

    return NULL;
}



LuaCEmbedTable  * raw_create_schema(LuaCEmbed *args,DtwSchema *schema){


    LuaCEmbedTable *created= lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(created,SCHEMA_POINTER,(long)schema);
    lua.tables.set_method(created,ADD_PRIMARY_KEYS,add_schema_primary_keys);
    lua.tables.set_method(created,COMMIT_METHOD,commit_schema);
    lua.tables.set_method(created,DELETE_METHOD,delete_schema);
    lua.tables.set_method(created,DANGEROUS_REMOVE_PROP_METHOD,dangerous_remove_schema_prop);
    lua.tables.set_method(created,DANGEROUS_RENAME_PROP_METHOD,dangerous_rename_schema_prop);
    lua.tables.set_method(created, GET_RESOURCE_MATCHING_PRIMARY_KEY_METHOD, get_resource_match_schema_by_primary_key);
    lua.tables.set_method(created,GET_RESOURCE_BY_NAME_ID,get_resource_by_name_id);
    lua.tables.set_method(created,LIST_METHOD,schema_list_resources);
    lua.tables.set_method(created,FIND_METHOD,schema_find_resource);
    lua.tables.set_method(created,MAP_METHOD,schema_map_resource);
    lua.tables.set_method(created,EACH_METHOD,schema_each);
    lua.tables.set_method(created,COUNT_METHOD,schema_count_resource);
    lua.tables.set_method(created,NEW_SCHEMA_METHOD,schema_new_insertion);

    return created;
}

LuaCEmbedResponse * create_schema(LuaCEmbed *args){
    char *path = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwSchema  *schma = dtw.schema.newSchema(path);
    LuaCEmbedTable *created =raw_create_schema(args,schma);
    return lua.response.send_table(created);
}
