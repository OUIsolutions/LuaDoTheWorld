//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end


LuaCEmbedResponse  * cache_clojure_factory(LuaCEmbedTable *self, LuaCEmbed *args){

    long expiration = LuaCembedTable_get_long_prop(self, "expiration");
    char *cache_dir = LuaCembedTable_get_string_prop(self, "cache_dir");
    
    // Get handle_errors property
    bool handle_errors = true;
    if(LuaCEmbedTable_get_type_prop(self, "handle_errors") != LUA_CEMBED_NIL){
        handle_errors = LuaCembedTable_get_bool_prop(self, "handle_errors");
    }

    LuaCEmbedTable *function_args = LuaCEmbed_transform_args_in_table(args);
    DtwHash *hasher = newDtwHash();
    ldtw_digest_table(function_args, hasher);

    DtwResource *database = new_DtwResource(cache_dir);
    
    // Handle cache_name if it exists
    DtwResource *cache_dir_resource = database;
    if(LuaCEmbedTable_get_type_prop(self, "cache_name") != LUA_CEMBED_NIL){
        char *cache_name = LuaCembedTable_get_string_prop(self, "cache_name");
        cache_dir_resource = DtwResource_sub_resource(database, cache_name);
    }
    
    DtwResource *cache_resource = DtwResource_sub_resource(cache_dir_resource, hasher->hash);
    DtwHash_free(hasher);
    DtwResource *result= DtwResource_sub_resource(cache_resource,"result.lua");
    DtwResource *error_resource = DtwResource_sub_resource(cache_resource, "error");
    DtwResource *last_execution_resource = DtwResource_sub_resource(cache_resource, "last_execution");

    bool execute_callback = false;
    bool cached_content = false;
    bool cached_error = false;
    if(expiration != -1){
        int last_execution_type = DtwResource_type(last_execution_resource);
        if(last_execution_type != DTW_COMPLEX_LONG_TYPE){
            execute_callback = true;
        }
        if(last_execution_type == DTW_COMPLEX_LONG_TYPE){
            long last_execution = DtwResource_get_long(last_execution_resource);
            long now = time(NULL);
            
            // If the cache entry has timed out, remove it
            if(now - last_execution > expiration){
                execute_callback = true;
            }
        }
    }
    
    if(!execute_callback){
        //database corruption
        if(DtwResource_type(result) == DTW_COMPLEX_STRING_TYPE){
            cached_content = true;
        }
        if(!cached_content && handle_errors){
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
        if(handle_errors){
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

//dtw.create_cache_function
LuaCEmbedResponse  * create_cache_function(LuaCEmbed *args){


    LuaCEmbedTable *entries = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    LuaCEmbedTable *object_respomse = LuaCembed_new_anonymous_table(args);   

    //--------------------------expiration Prop--------------------------
    long expiration = -1;
    if(LuaCEmbedTable_get_type_prop(entries, "expiration") != LUA_CEMBED_NIL){
        expiration = LuaCembedTable_get_long_prop(entries, "expiration");
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    LuaCEmbedTable_set_long_prop(object_respomse, "expiration", expiration);

    //--------------------------Handle Errors Prop--------------------------
    bool handle_errors = true;
    if(LuaCEmbedTable_get_type_prop(entries, "handle_errors") != LUA_CEMBED_NIL){
        handle_errors = LuaCembedTable_get_bool_prop(entries, "handle_errors");
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    LuaCEmbedTable_set_bool_prop(object_respomse, "handle_errors", handle_errors);

    //--------------------------Cache Dir Prop--------------------------
    char *cache_dir = LuaCembedTable_get_string_prop(entries, "cache_dir");
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    LuaCEmbedTable_set_string_prop(object_respomse, "cache_dir", cache_dir);
    
    //--------------------------Cache Name Prop--------------------------
    char *cache_name = NULL;
    if(LuaCEmbedTable_get_type_prop(entries, "cache_name") != LUA_CEMBED_NIL){
        cache_name = LuaCembedTable_get_string_prop(entries, "cache_name");
        if(LuaCEmbed_has_errors(args)){
            char *error_msg = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error_msg);
        }
        LuaCEmbedTable_set_string_prop(object_respomse, "cache_name", cache_name);
    }
  
    
    if(LuaCEmbedTable_get_type_prop(entries,"callback") != LUA_CEMBED_FUNCTION){
        return LuaCEmbed_send_error("Cache function must have a callback function");
    }
    
    LuaCEmbedTable_set_table_prop_with_table_prop(object_respomse, "callback", entries, "callback");

    LuaCEmbedTable_set_method(object_respomse, "execute", cache_clojure_factory);

    return LuaCEmbed_send_table_prop(object_respomse, "execute");
}



