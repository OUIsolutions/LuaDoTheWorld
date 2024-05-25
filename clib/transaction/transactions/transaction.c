


LuaCEmbedResponse * transaction_write(LuaCEmbedTable *self,LuaCEmbed *args){

    char *filename = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }


    Writeble  write_obj = create_writeble(args,1);
    if(write_obj.error){
        return write_obj.error;
    }
    bool is_binary = false;
    for(int i = 0; i < write_obj.size; i++){
        if(write_obj.content[i] == '\0'){
            is_binary = true;
        }
    }
    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    dtw.transaction.write_any(t,filename,write_obj.content,write_obj.size,is_binary);
    return  lua.response.send_table(self);
}


LuaCEmbedResponse * transaction_remove_any(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *source = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    dtw.transaction.delete_any(t,source);
    return  lua.response.send_table(self);
}

LuaCEmbedResponse * transaction_copy_any(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *source = lua.args.get_str(args,0);
    char *dest = lua.args.get_str(args,1);

    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    dtw.transaction.copy_any(t,source,dest);
    return  lua.response.send_table(self);
}

LuaCEmbedResponse * transaction_move_any(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *source = lua.args.get_str(args,0);
    char *dest = lua.args.get_str(args,1);

    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    dtw.transaction.move_any(t,source,dest);
    return  lua.response.send_table(self);
}

LuaCEmbedResponse * transaction_commit(LuaCEmbedTable *self,LuaCEmbed *args) {

    const char *path = NULL;
    if(lua.args.size(args) > 0){
        path  = lua.args.get_str(args,0);
    }
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    dtw.transaction.commit(t,path);
    return  lua.response.send_table(self);
}


LuaCEmbedResponse * transaction_dumps_to_json_file(LuaCEmbedTable *self,LuaCEmbed *args) {

    char *filename = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    dtw.transaction.dumps_transaction_to_json_file(t,filename);

    return  lua.response.send_table(self);
}

LuaCEmbedResponse * transaction_dumps_to_json_string(LuaCEmbedTable *self,LuaCEmbed *args) {

    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    cJSON *parsed = dtw.transaction.dumps_transaction_to_json(t);
    char * content = cJSON_Print(parsed);

    LuaCEmbedResponse  *response = lua.response.send_str(content);
    cJSON_Delete(parsed);
    free(content);
    return response;
}

LuaCEmbedResponse * transaction_delete(LuaCEmbedTable *self,LuaCEmbed *args) {

    DtwTransaction *t = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    bool ref = lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    if(!ref){
        dtw.transaction.free(t);
    }

    return lua.response.send_table(self);
}

void  private_transaction_add_base_methods(LuaCEmbedTable *self,DtwTransaction *transaction){
    lua.tables.set_long_prop(self,TRANSACTION_POINTER,(long long)transaction);
    lua.tables.set_method(self,WRITE_METHOD,transaction_write);
    lua.tables.set_method(self,COPY_ANY_METHOD,transaction_copy_any);
    lua.tables.set_method(self,REMOVE_ANY_METHOD,transaction_remove_any);
    lua.tables.set_method(self,MOVE_ANY_METHOD,transaction_move_any);
    lua.tables.set_method(self,COPY_ANY_METHOD,transaction_copy_any);
    lua.tables.set_method(self,COMMIT_METHOD,transaction_commit);
    lua.tables.set_method(self,DUMP_TO_JSON_FILE_METHOD,transaction_dumps_to_json_file);
    lua.tables.set_method(self,DUMP_TO_JSON_STRING,transaction_dumps_to_json_string);
    lua.tables.set_method(self,DELETE_METHOD,transaction_delete);
}

LuaCEmbedResponse * create_empty_transaction_from_json_string(LuaCEmbed *args) {

    char *content = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    UniversalGarbage *garbage = newUniversalGarbage();

    cJSON * parsed = cJSON_Parse(content);
    UniversalGarbage_add(garbage,cJSON_Delete,parsed);
    if(parsed == NULL) {
        LuaCEmbedResponse *response  = lua.response.send_error(INVALID_JSON_STRING);
        UniversalGarbage_free(garbage);
        return  response;
    }

    DtwTransaction * transaction_obj = dtw.transaction.newTransaction_from_json(parsed);
    if(transaction_obj == NULL) {
        DtwJsonTransactionError * error =  dtw_validate_json_transaction(parsed);
        UniversalGarbage_add(garbage,DtwJsonTransactionError_free,error);
        LuaCEmbedResponse *response  = lua.response.send_error(error->mensage);
        UniversalGarbage_free(garbage);
        return  response;
    }

    LuaCEmbedTable * self = lua.tables.new_anonymous_table(args);
    lua.tables.set_method(self,IS_A_REF,false);
    private_transaction_add_base_methods(self,transaction_obj);
    UniversalGarbage_free(garbage);
    return lua.response.send_table(self);


}


LuaCEmbedResponse * create_empty_transaction_from_json_file(LuaCEmbed *args) {

    char *filename = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    UniversalGarbage *garbage = newUniversalGarbage();

    char *content = dtw.load_string_file_content(filename);
    UniversalGarbage_add_simple(garbage,content);

    if(content == NULL) {
        char *error = private_LuaCembed_format(FILE_NOT_FOUND,filename);
        UniversalGarbage_add_simple(garbage,error);
        LuaCEmbedResponse *response  = lua.response.send_error(error);
        UniversalGarbage_free(garbage);
        return  response;
    }
    cJSON * parsed = cJSON_Parse(content);
    UniversalGarbage_add(garbage,cJSON_Delete,parsed);


    if(parsed == NULL) {
        char *error = private_LuaCembed_format(INVALID_JSON_FILE,filename);
        UniversalGarbage_add_simple(garbage,error);
        LuaCEmbedResponse *response  = lua.response.send_error(error);
        UniversalGarbage_free(garbage);
        return  response;
    }


    DtwTransaction * transaction_obj = dtw.transaction.newTransaction_from_json(parsed);
    if(transaction_obj == NULL) {
        DtwJsonTransactionError * error =  dtw_validate_json_transaction(parsed);
        UniversalGarbage_add(garbage,DtwJsonTransactionError_free,error);
        LuaCEmbedResponse *response  = lua.response.send_error(error->mensage);
        UniversalGarbage_free(garbage);
        return  response;
    }

    LuaCEmbedTable * self = lua.tables.new_anonymous_table(args);
    lua.tables.set_method(self,IS_A_REF,false);
    private_transaction_add_base_methods(self,transaction_obj);
    UniversalGarbage_free(garbage);
    return lua.response.send_table(self);


}

LuaCEmbedResponse * create_empty_transacton(LuaCEmbed *args){
    LuaCEmbedTable * self = lua.tables.new_anonymous_table(args);
    lua.tables.set_bool_prop(self,IS_A_REF,false);
    DtwTransaction *t = dtw.transaction.newTransaction();
    private_transaction_add_base_methods(self,t);
    return lua.response.send_table(self);
}

