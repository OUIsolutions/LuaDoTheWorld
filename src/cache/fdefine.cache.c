//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

//these its the clojure that its return on dtw.create_cache_function
LuaCEmbedResponse  * cache_clojure_factory(LuaCEmbedTable *self, LuaCEmbed *args){

    long timeout = LuaCembedTable_get_long_prop(self, "timeout");
    char *cache_dir = LuaCembedTable_get_string_prop(self, "cache_dir");


    LuaCEmbedTable *function_args = LuaCEmbed_transform_args_in_table(args);
    DtwHash *hasher = newDtwHash();
    ldtw_digest_table(function_args, hasher);

    DtwResource *database = new_DtwResource(cache_dir);
    DtwResource *cache_resource = DtwResource_sub_resource(database, hasher->hash);
    DtwHash_free(hasher);
    DtwResource *result= DtwResource_sub_resource(cache_resource,"result.lua");
    DtwResource *error_resource = DtwResource_sub_resource(cache_resource, "error");
    DtwResource *last_execution_resource = DtwResource_sub_resource(cache_resource, "last_execution");

    bool execute_callback = false;
    bool cached_content = false;
    bool cached_error = false;
    if(timeout != -1){
        int last_execution_type = DtwResource_type(last_execution_resource);
        if(last_execution_type != DTW_COMPLEX_LONG_TYPE){
            execute_callback = true;
        }
        if(last_execution_type == DTW_COMPLEX_LONG_TYPE){
            long last_execution = DtwResource_get_long(last_execution_resource);
            long now = time(NULL);
            if(now - last_execution > timeout){
                execute_callback = true;
            }
        }
    }
    
    if(!execute_callback){
        //database corruption
        if(DtwResource_type(result) == DTW_COMPLEX_STRING_TYPE){
            cached_content = true;
        }
        if(!cached_content){
            if(DtwResource_type(error_resource) == DTW_COMPLEX_STRING_TYPE){
                cached_error = true;
            }
        }
    }

    if(cached_content){
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

    if(cached_error){
        char *error_msg = DtwResource_get_string(error_resource);
        LuaCEmbedResponse *response =  LuaCEmbed_send_error(error_msg);
        DtwResource_free(database);
        return response;
    }


    LuaCEmbedTable *callback_response = LuaCEmbedTable_run_prop_function(
        self,
        "callback",
        function_args,
        1
    );
    DtwResource_set_long(
        last_execution_resource,
        time(NULL)
    );


    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        DtwResource_set_string(error_resource, error_msg);
        DtwResource_commit(database);
        DtwResource_free(database);           
        return LuaCEmbed_send_error(error_msg);
    }

    privateLuaDtwStringAppender *appender = newprivateLuaDtwStringAppender();
    ldtw_serialize_first_value_of_table(appender, callback_response);
    DtwResource_set_any(
        result,
        appender->buffer,
        appender->length,
        false
    );

    // implement the execution
    DtwResource_commit(database);
    DtwResource_free(database);
    privateLuaDtwStringAppender_free(appender);
    return LuaCEmbed_send_multi_return(callback_response);
}

//dtw.create_cache_function
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

    LuaCEmbedTable_set_method(object_respomse, "execute", cache_clojure_factory);

    return LuaCEmbed_send_table_prop(object_respomse, "execute");
}


//dtw.execute_cache
LuaCEmbedResponse  * ldtw_execute_cache(LuaCEmbed *args){
    LuaCEmbedTable *entries = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error( error_msg);
    }

    //--------------------------Timeout Prop--------------------------
    long timeout = -1;
    if(LuaCEmbedTable_get_type_prop(entries, "timeout") != LUA_CEMBED_NIL){
        timeout = LuaCembedTable_get_long_prop(entries, "timeout");
    }

    bool store_errors = true;
    if(LuaCEmbedTable_get_type_prop(entries, "store_errors") != LUA_CEMBED_NIL){
        store_errors = LuaCembedTable_get_bool_prop(entries, "store_errors");
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
  
    if(LuaCEmbedTable_get_type_prop(entries,"callback") != LUA_CEMBED_FUNCTION){
        return LuaCEmbed_send_error("Cache function must have a callback function");
    }

    DtwHash *hasher = newDtwHash();
    int input_type = LuaCEmbedTable_get_type_prop(entries, "input");
    if(input_type == LUA_CEMBED_STRING){
        char *content = LuaCembedTable_get_string_prop(entries, "input");
        DtwHash_digest_string(hasher, content);
    }
    if(input_type == LUA_CEMBED_BOOL){
        bool content = LuaCembedTable_get_bool_prop(entries, "input");
        DtwHash_digest_bool(hasher, content);
    }
    if(input_type == LUA_CEMBED_NUMBER){
        double content = LuaCCembedTable_get_double_prop(entries, "input");
        DtwHash_digest_double(hasher, content);
    }
    if(input_type == LUA_CEMBED_NIL){
        DtwHash_digest_string(hasher, "nil");
    }
    if(input_type == LUA_CEMBED_TABLE){
        LuaCEmbedTable *table = LuaCEmbedTable_get_sub_table_by_key(entries, "input");
        ldtw_digest_table(table, hasher);
    }

    
    DtwResource *database = new_DtwResource(cache_dir);
    DtwResource *cache_resource = DtwResource_sub_resource(database, hasher->hash);
    DtwHash_free(hasher);

    DtwResource *result= DtwResource_sub_resource(cache_resource,"result.lua");
    DtwResource *error_resource = DtwResource_sub_resource(cache_resource, "error");
    DtwResource *last_execution_resource = DtwResource_sub_resource(cache_resource, "last_execution");

    bool execute_callback = false;
    bool cached_content = false;
    bool cached_error = false;
    if(timeout != -1){
        int last_execution_type = DtwResource_type(last_execution_resource);
        if(last_execution_type != DTW_COMPLEX_LONG_TYPE){
            execute_callback = true;
        }
        if(last_execution_type == DTW_COMPLEX_LONG_TYPE){
            long last_execution = DtwResource_get_long(last_execution_resource);
            long now = time(NULL);
            if(now - last_execution > timeout){
                execute_callback = true;
            }
        }
    }
    
    if(!execute_callback){
        //database corruption
        if(DtwResource_type(result) == DTW_COMPLEX_STRING_TYPE){
            cached_content = true;
        }
        if(!cached_content){
            if(DtwResource_type(error_resource) == DTW_COMPLEX_STRING_TYPE){
                cached_error = true;
            }
        }
    }

    if(cached_content){
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

    if(cached_error){
        char *error_msg = DtwResource_get_string(error_resource);
        LuaCEmbedResponse *response =  LuaCEmbed_send_error(error_msg);
        DtwResource_free(database);
        return response;
    }


    LuaCEmbedTable *callback_response = LuaCEmbedTable_run_prop_function(
        entries,
        "callback",
        NULL,
        1
    );

    DtwResource_set_long(
        last_execution_resource,
        time(NULL)
    );


    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        if(store_errors){
            DtwResource_set_string(error_resource, error_msg);
            DtwResource_commit(database);
        }
        DtwResource_free(database);           
        return LuaCEmbed_send_error(error_msg);
    }

    privateLuaDtwStringAppender *appender = newprivateLuaDtwStringAppender();
    ldtw_serialize_first_value_of_table(appender, callback_response);
    DtwResource_set_any(
        result,
        appender->buffer,
        appender->length,
        false
    );

    // implement the execution
    DtwResource_commit(database);
    DtwResource_free(database);
    privateLuaDtwStringAppender_free(appender);
    return LuaCEmbed_send_multi_return(callback_response);

}


//dtw.clear_expired_cache
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