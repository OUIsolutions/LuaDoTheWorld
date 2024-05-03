
LuaCEmbedResponse  *delete_bytes(LuaCEmbedTable *self,LuaCEmbed *args){

    
    long pointer = lua.tables.get_long_prop(self,CONTENT_POINTER);
    unsigned  char *converted = (unsigned  char *)pointer;
    free(converted);
    return NULL;
}

LuaCEmbedTable * create_bytes(LuaCEmbed  *args,unsigned  char *content,long size){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,DTW_TYPE,BYTE_TYPE);
    lua.tables.set_long_prop(self,SIZE,size);
    lua.tables.set_long_prop(self,CONTENT_POINTER,(long)content);
    lua.tables.set_method(self, DELETE_METHOD, delete_bytes);
    return self;
}