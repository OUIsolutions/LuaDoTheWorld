//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end


LuaCEmbedResponse  * ldtw_execute_cache_callback(LuaCEmbedTable *self, LuaCEmbed *args){
    printf("Executing cache callback\n");

    long timeout = LuaCembedTable_get_long_prop(self, "timeout");
    char *cache_dir = LuaCembedTable_get_string_prop(self, "cache_dir");


    LuaCEmbedTable *function_args = LuaCEmbed_transform_args_in_table(args);
    DtwHash *hasher = newDtwHash();
    ldtw_digest_table(function_args, hasher);

    DtwResource *database = new_DtwResource(cache_dir);
    DtwResource *cache_resource = DtwResource_sub_resource(database, hasher->hash);
    DtwHash_free(hasher);
    DtwResource *timeout_resource = DtwResource_sub_resource(cache_resource, "timeout");

    bool execute_callback = false;
    if(timeout != -1){
        int timeout_type = DtwResource_type(timeout_resource);
        if(timeout_type != DTW_COMPLEX_LONG_TYPE){
            execute_callback = true;
        }
        if(timeout_type == DTW_COMPLEX_LONG_TYPE){
            long last_execution = DtwResource_get_long(timeout_resource);
            long now = time(NULL);
            if(now - last_execution > timeout){
                execute_callback = true;
            }
        }
    }
    DtwResource *result= DtwResource_sub_resource(cache_resource,"result.lua");

    if(!execute_callback){
        if(DtwResource_type(result) != DTW_COMPLEX_STRING_TYPE){
            execute_callback = true;
        }
    }
    bool loaded_in_memory =  !execute_callback;
    if(loaded_in_memory){
        char *content = DtwResource_get_string(result);

        ///these its a quick hack ,since luacembembed dont provide a way 
        LuaCEmbedTable *response_table = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_evaluation(response_table,content);
        if(!LuaCEmbed_has_errors(args)){
            DtwResource_free(database);            
            return LuaCEmbed_send_multi_return(response_table);
        }
        LuaCEmbed_clear_errors(args);
        //it will execute the callback
    }

    LuaCEmbedTable *callback_response = LuaCEmbedTable_run_prop_function(
        self,
        "callback",
        function_args,
        1
    );
    privateLuaDtwStringAppender *appender = newprivateLuaDtwStringAppender();
    ldtw_serialize_first_value_of_table(appender, callback_response);
    DtwResource_set_any(
        result,
        appender->buffer,
        appender->length,
        false
    );
    DtwResource_set_long(
        timeout_resource,
        time(NULL)
    );

    // implement the execution
    DtwResource_commit(database);
    DtwResource_free(database);
    privateLuaDtwStringAppender_free(appender);
    return LuaCEmbed_send_multi_return(callback_response);
}


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
  
    
    if(LuaCEmbedTable_get_type_prop(entries,"callback") != LUA_CEMBED_FUNCTION){
        return LuaCEmbed_send_error("Cache function must have a callback function");
    }
    
    LuaCEmbedTable_set_table_prop_with_table_prop(object_respomse, "callback", entries, "callback");

    LuaCEmbedTable_set_method(object_respomse, "execute", ldtw_execute_cache_callback);

    return LuaCEmbed_send_table_prop(object_respomse, "execute");
}