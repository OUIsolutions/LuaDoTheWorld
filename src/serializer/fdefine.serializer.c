//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

LuaCEmbedResponse *ldtw_serialize_var(LuaCEmbed *args){

    int type  = LuaCEmbed_get_arg_type(args, 0);

    privateLuaDtwStringAppender *appender = newprivateLuaDtwStringAppender();
    
}