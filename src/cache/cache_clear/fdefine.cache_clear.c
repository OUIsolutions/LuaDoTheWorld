//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end




//dtw.clear_cache
LuaCEmbedResponse  * ldtw_clear_expired_cache(LuaCEmbed *args){


    char *cache_dir = LuaCEmbed_get_str_arg(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    long timeout = LuaCEmbed_get_long_arg(args, 1);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwResource *database = new_DtwResource(cache_dir);
    DtwResourceArray *sub_resources = DtwResource_sub_resources(database);

    long now = time(NULL);
    for(long i = 0; i < sub_resources->size; i++){
        DtwResource *current_resource = sub_resources->resources[i];
        DtwResource *last_execution_resource = DtwResource_sub_resource(current_resource, "last_execution");
        
        // Check if last_execution file exists and is valid
        int last_execution_type = DtwResource_type(last_execution_resource);
        if(last_execution_type == DTW_COMPLEX_LONG_TYPE){
            long last_execution = DtwResource_get_long(last_execution_resource);
            
            // If the cache entry has timed out, remove it
            if(now - last_execution > timeout){
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
}