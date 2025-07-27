//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end




//dtw.clear_cache
LuaCEmbedResponse  * ldtw_clear_old_cache(LuaCEmbed *args){

    LuaCEmbedTable *entries = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    //--------------------------Timeout Prop--------------------------
    long timeout = -1;
    if(LuaCEmbedTable_get_type_prop(entries, "timeout") != LUA_CEMBED_NIL){
        timeout = LuaCembedTable_get_long_prop(entries, "timeout");
    }
    
    //-------------------------- Cache name Prop--------------------------
    char *cache_name = LuaCembedTable_get_string_prop(entries, "cache_name");
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);     
    }

    //--------------------------Cache Dir Prop--------------------------
    char *cache_dir = LuaCembedTable_get_string_prop(entries, "cache_dir");
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwResource * database = new_DtwResource(cache_dir);
    DtwResource *cache_elements = DtwResource_sub_resource(database,cache_name);
    DtwResourceArray *sub_resources = DtwResource_sub_resources(cache_elements);
    long now = time(NULL);
    
    for(long i = 0; i < sub_resources->size; i++){
        DtwResource *current_resource = sub_resources->resources[i];
        DtwResource *last_execution_resource = DtwResource_sub_resource(current_resource, "last_execution");
        
        // Check if last_execution file exists and is valid
        int last_execution_type = DtwResource_type(last_execution_resource);
        if(last_execution_type == DTW_COMPLEX_LONG_TYPE){
            long last_execution = DtwResource_get_long(last_execution_resource);
            
            // If the cache entry has timed out, remove it
            if(timeout > 0 && (now - last_execution > timeout)){
                DtwResource_destroy(current_resource);
            }
        }
        else {
            // If last_execution is not valid, consider it timed out and remove
            DtwResource_destroy(current_resource);
        }
    }
    
    DtwResource_commit(database);
    DtwResource_free(database);
    
    return NULL;
}