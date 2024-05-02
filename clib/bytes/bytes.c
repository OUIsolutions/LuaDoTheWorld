

LuaCEmbedTable * create_bytes(LuaCEmbed  *args,unsigned  char *content,long size){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,DTW_TYPE,BYTE_TYPE);
    lua.tables.set_long_prop(self,SIZE,size);
    lua.tables.set_long_prop(self,CONTENT_POINTER,(long)content);

}