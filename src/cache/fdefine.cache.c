//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



LuaCEmbedResponse  * create_cache_function(LuaCEmbed *args){


    LuaCEmbedTable *entries = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error( error_msg);
    }
    LuaCEmbedTable *object_respomse = LuaCembed_new_anonymous_table(args);   

    //--------------------------Timeout Prop--------------------------
    long timeout = -1;
    if(LuaCEmbedTable_get_type_prop(entries, "timeout") != LUA_CEMBED_NIL){
        timeout = LuaCembedTable_get_long_prop(entries, "timeout");
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error( error_msg);
    }
    LuaCEmbedTable_set_long_prop(object_respomse, "timeout", timeout);

    //--------------------------Cache Dir Prop--------------------------
    char *cache_dir = LuaCembedTable_get_string_prop(entries, "cache_dir");
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    LuaCEmbedTable_set_string_prop(object_respomse, "cache_dir", cache_dir);
  
    
    


    return NULL;
}