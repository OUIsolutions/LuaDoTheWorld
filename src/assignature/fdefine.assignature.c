//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

void ldtw_digest_table(LuaCEmbedTable *table,DtwHash *hasher){
    
    
    long size  = LuaCEmbedTable_get_full_size(table);
    bool existed_some_key = false;
    for(int i = 0; i < size;i++){
        bool has_key = LuaCembedTable_has_key_at_index(table, i);
        if (has_key) {
            existed_some_key = true;
            continue;
        }
        int type_item = LuaCEmbedTable_get_type_by_index(table, i);
        if (type_item == LUA_CEMBED_STRING) {
            char *str = LuaCEmbedTable_get_string_by_index(table, i);
            DtwHash_digest_string(hasher, str);
        }
         if (type_item == LUA_CEMBED_BOOL) {
            bool b = LuaCEmbedTable_get_bool_by_index(table, i);
            DtwHash_digest_bool(hasher, b);
        } 
         if (type_item == LUA_CEMBED_NUMBER) {
            double d = LuaCEmbedTable_get_double_by_index(table, i);
            DtwHash_digest_double(hasher, d);
        } 
        if (type_item == LUA_CEMBED_NIL) {
            DtwHash_digest_string(hasher, "nil");
        } 
        if (type_item == LUA_CEMBED_TABLE) {
            LuaCEmbedTable *sub_table = LuaCEmbedTable_get_sub_table_by_index(table, i);
            ldtw_digest_table(sub_table, hasher);
        }
    }

    if(!existed_some_key){
        return;
    }
    DtwStringArray *keys = newDtwStringArray();
    for(int i = 0; i < size;i++){
        bool has_key = LuaCembedTable_has_key_at_index(table, i);
        if (!has_key) {
            continue;
        }
        char *key = LuaCembedTable_get_key_by_index(table, i);
        DtwStringArray_append(keys,key);
    }
    DtwStringArray_sort(keys);
    for(int i = 0; i < keys->size;i++){
        char *key = keys->strings[i];
        DtwHash_digest_string(hasher, key);

        int type = LuaCEmbedTable_get_type_prop(table, key);
        if (type == LUA_CEMBED_STRING) {
            char *str = LuaCembedTable_get_string_prop(table, key);
            DtwHash_digest_string(hasher, str);     
        } 
        if (type == LUA_CEMBED_BOOL) {
            bool b = LuaCembedTable_get_bool_prop(table, key);
            DtwHash_digest_bool(hasher, b);
        } 
        if (type == LUA_CEMBED_NUMBER) {
            double d = LuaCembedTable_get_double_prop(table, key);
            DtwHash_digest_double(hasher, d);
        } 
        if (type == LUA_CEMBED_NIL) {
            DtwHash_digest_string(hasher, "nil");
        } 
        if (type == LUA_CEMBED_TABLE) {
            LuaCEmbedTable *sub_table = LuaCEmbedTable_get_sub_table_by_key(table, key);
            ldtw_digest_table(sub_table, hasher);
        } 
         
    }
    DtwStringArray_free(keys);
}

LuaCEmbedResponse *ldtw_assign_element(LuaCEmbed *args){
    
    DtwHash *hasher = newDtwHash();

    int type = LuaCEmbed_get_arg_type(args, 0);
    if(type == LUA_CEMBED_STRING){
        char *content = LuaCEmbed_get_str_arg(args, 0);
        DtwHash_digest_string(hasher, content);
    }
    if(type == LUA_CEMBED_BOOL){
        bool content = LuaCEmbed_get_bool_arg(args, 0);
        DtwHash_digest_bool(hasher, content);
    }
    if(type == LUA_CEMBED_NUMBER){
        double content = LuaCEmbed_get_double_arg(args, 0);
        DtwHash_digest_double(hasher, content);
    }
    if(type == LUA_CEMBED_NIL){
        DtwHash_digest_string(hasher, "nil");
    }
    if(type == LUA_CEMBED_TABLE){
        LuaCEmbedTable *table = LuaCEmbed_get_arg_table(args, 0);
        ldtw_digest_table(table, hasher);
    }
    LuaCEmbedResponse *response =LuaCEmbed_send_str(hasher->hash);
    DtwHash_free(hasher);
    return response;
}