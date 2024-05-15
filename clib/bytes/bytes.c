
LuaCEmbedResponse  *delete_bytes(LuaCEmbedTable *self,LuaCEmbed *args){

    bool ref = lua.tables.get_bool_prop(self,IS_A_REF);
    if(ref){
        return NULL;
    }

    long pointer = lua.tables.get_long_prop(self,CONTENT_POINTER);
    unsigned  char *converted = (unsigned  char *)pointer;
    if(converted){
        free(converted);
    }
    return NULL;

}
LuaCEmbedResponse  *private_get_bytes_at(LuaCEmbedTable *self, long index){

    long converted_index = index -1;
    long size = lua.tables.get_long_prop(self,SIZE);
    if(index >=size){
        return  lua.response.send_error(INVALID_INDEX);
    }
    unsigned char *value = (unsigned  char*)lua.tables.get_long_prop(self,CONTENT_POINTER);
    return lua.response.send_long((long)value[converted_index]);
}

LuaCEmbedResponse  *get_byte_at_index(LuaCEmbedTable *self, LuaCEmbed *args) {

    long index = lua.args.get_long(args, 1);

    if (lua.has_errors(args)) {
        char *error_message = lua.get_error_message(args);
        return lua.response.send_error(error_message);
    }
    return private_get_bytes_at(self,index);
}

LuaCEmbedResponse  *get_byte_at_method(LuaCEmbedTable *self, LuaCEmbed *args){
    long index = lua.args.get_long(args, 0);

    if (lua.has_errors(args)) {
        char *error_message = lua.get_error_message(args);
        return lua.response.send_error(error_message);
    }
    return private_get_bytes_at(self,index);
}
LuaCEmbedResponse  *bytes_representation(LuaCEmbedTable *self, LuaCEmbed *args){
    return lua.response.send_str(BYTE_STRING);
}
LuaCEmbedTable * create_bytes(LuaCEmbed  *args,unsigned  char *content,long size){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,DTW_TYPE,BYTE_TYPE);
    lua.tables.set_bool_prop(self,IS_A_REF,false);
    lua.tables.set_long_prop(self,SIZE,size);
    lua.tables.set_long_prop(self,CONTENT_POINTER,(long)content);
    lua.tables.set_method(self, INDEX_METHOD, get_byte_at_index);
    lua.tables.set_method(self, TO_STRING_METHOD, bytes_representation);
    lua.tables.set_method(self, GET_BYTE_AT_METHOD, get_byte_at_method);
    lua.tables.set_method(self, DELETE_METHOD, delete_bytes);
    return self;
}

LuaCEmbedTable * create_bytes_ref(LuaCEmbed  *args,unsigned  char *content,long size){
    LuaCEmbedTable *self = create_bytes(args,content,size);
    lua.tables.set_bool_prop(self,IS_A_REF,true);
    return self;
}

LuaCEmbedResponse * is_byte(LuaCEmbed  *args){
    if(lua.args.get_type(args,0) != lua.types.TABLE){
        return lua.response.send_bool(false);
    }
    LuaCEmbedTable *possible_byte = lua.args.get_table(args,0);
    if(lua.tables.get_type_prop(possible_byte,DTW_TYPE) != lua.types.NUMBER){
        return lua.response.send_bool(false);
    }
    long type = lua.tables.get_long_prop(possible_byte,DTW_TYPE);
    if(type != BYTE_TYPE){
        return lua.response.send_bool(false);
    }
    return lua.response.send_bool(true);

}