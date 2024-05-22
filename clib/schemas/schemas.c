

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

LuaCEmbedResponse  * Resource_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args){

    DtwSchema *schema = (DtwSchema*)lua.tables.get_long_prop(self,SCHEMA_POINTER);
    DtwResource  *created = dtw.schema.new_insertion(schema);
    LuaCEmbedTable  *sub = raw_create_resource(args,created);
    return lua.response.send_table(sub);
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


LuaCEmbedTable  * raw_create_schema(LuaCEmbed *args,DtwSchema *schema){


    LuaCEmbedTable *created= lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(created,SCHEMA_POINTER,(long long )schema);
    lua.tables.set_method(created,ADD_PRIMARY_KEYS,add_schema_primary_keys);


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
