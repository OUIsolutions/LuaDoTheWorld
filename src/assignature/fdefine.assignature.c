//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end


LuaCEmbedResponse ldtw_assign_element(LuaCEmbed *args){
    
    DtwHash *hasher = newDtwHash();

    int type = LuaCEmbed_get_arg_type(args, 0);
    if(type == LUA_CEMBED_STRING){
        char *content = LuaCEmbed_get_str_arg(args, 0);
        DtwHash_digest_string(hasher, content);
    }
    
}