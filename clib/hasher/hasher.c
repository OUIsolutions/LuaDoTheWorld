
LuaCEmbedResponse * hasher_digest_file(LuaCEmbedTable *self,LuaCEmbed *args){
    char *filename = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    
    DtwHash *hash = (DtwHash*)lua.tables.get_long_prop(self,HASH_POINTER);

}

LuaCEmbedResponse * hasher_digest_folder(LuaCEmbedTable *self,LuaCEmbed *args);


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

LuaCEmbedResponse * hasher_get_value(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwHash *hash = (DtwHash*)lua.tables.get_long_prop(self,HASH_POINTER);
    return lua.response.send_str(hash->hash);
}


LuaCEmbedResponse * create_hasher(LuaCEmbed *args){
    LuaCEmbedTable * self = lua.tables.new_anonymous_table(args);
    DtwHash *hash = newDtwHash();

    lua.tables.set_long_prop(self,HASH_POINTER,(long)hash);
    lua.tables.set_method(self,DIGESST,hasher_digest);
    lua.tables.set_method(self, TO_STRING_METHOD, hasher_get_value);
    lua.tables.set_method(self, GET_VALUE_METHOD, hasher_get_value);
    lua.tables.set_method(self, DELETE_METHOD, delete_hasher);
    return lua.response.send_table(self);

}
