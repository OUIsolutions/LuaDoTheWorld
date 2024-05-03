

LuaCEmbedResponse * delete_hasher(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwHash *hash = (DtwHash*)lua.tables.get_long_prop(self,HASH_POINTER);
    dtw.hash.free(hash);
    return NULL;
}

LuaCEmbedResponse * hasher_digest(LuaCEmbedTable *self,LuaCEmbed *args){
    Writeble write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwHash *hash = (DtwHash*)lua.tables.get_long_prop(self,HASH_POINTER);
    dtw.hash.digest_any(hash,write_obj.content,write_obj.size);
    Writeble_free(&write_obj);
    return NULL;
}

LuaCEmbedResponse * create_hasher(LuaCEmbed *args){
    LuaCEmbedTable * self = lua.tables.new_anonymous_table(args);
    DtwHash *hash = newDtwHash();

    lua.tables.set_long_prop(self,HASH_POINTER,(long)hash);
    lua.tables.set_method(self,DIGESST,hasher_digest);
    lua.tables.set_method(self,LUA_DELETE,delete_hasher);
    return lua.response.send_table(self);
}
