//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

void ldtw_digest_table(LuaCEmbedTable *table,DtwHash *hasher){
   
    
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