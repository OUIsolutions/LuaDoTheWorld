


LuaCEmbedResponse  * transaction_index(LuaCEmbedTable *self,LuaCEmbed *args){

    long index = lua.args.get_long(args,1);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return lua.response.send_error(error);
    }
    long converted = index -1;

    DtwTransaction *transaction = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    if(converted >= transaction->size || converted < 0){
        return NULL;
    }
    LuaCEmbedTable  *table = raw_create_action_transaction(args,transaction->actions[converted]);
    return lua.response.send_table(table);
}

LuaCEmbedResponse  * transaction_foreach(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTransaction *transaction = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    for(long i = 0 ; i < transaction->size; i++){
        DtwActionTransaction *action = transaction->actions[i];
        LuaCEmbedTable  *table = raw_create_action_transaction(args,action);
        LuaCEmbedTable  * args_of_callbac = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_of_callbac,table);
        lua.args.run_lambda(args,0,args_of_callbac,0);
        if(lua.has_errors(args)){
            char *error = lua.get_error_message(args);
            return lua.response.send_error(error);
        }
    }
    return  NULL;
}

LuaCEmbedResponse  * transaction_map(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwTransaction *transaction = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    LuaCEmbedTable *final_map = lua.tables.new_anonymous_table(args);
    for(long i = 0 ; i < transaction->size; i++){
        DtwActionTransaction *action = transaction->actions[i];
        LuaCEmbedTable  *table = raw_create_action_transaction(args,action);
        LuaCEmbedTable  * args_of_callbac = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_of_callbac,table);
        LuaCEmbedTable * response_values = lua.args.run_lambda(args,0,args_of_callbac,1);
        if(lua.has_errors(args)){
            char *error = lua.get_error_message(args);
            return lua.response.send_error(error);
        }
        int response_type =lua.tables.get_type_by_index(response_values,0);
        if(response_type!= LUA_CEMBED_NIL && response_type != LUA_CEMBED_NOT_FOUND){
            lua.tables.append_evaluation(final_map,"%s[1]",response_values->global_name);
        }
    }

    return  lua.response.send_table(final_map);
}

LuaCEmbedResponse  * transaction_find(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwTransaction *transaction = (DtwTransaction*)lua.tables.get_long_prop(self,TRANSACTION_POINTER);
    for(long i = 0 ; i < transaction->size; i++){
        DtwActionTransaction *action = transaction->actions[i];
        LuaCEmbedTable  *table = raw_create_action_transaction(args,action);
        LuaCEmbedTable  * args_of_callbac = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_of_callbac,table);
        LuaCEmbedTable * response_values = lua.args.run_lambda(args,0,args_of_callbac,1);
        if(lua.has_errors(args)){
            char *error = lua.get_error_message(args);
            return lua.response.send_error(error);
        }
        int response_type =lua.tables.get_type_by_index(response_values,0);
        if(response_type ==  lua.types.BOOL){
            return lua.response.send_bool(
                    lua.tables.get_bool_by_index(response_values,0)
                    );
        }
    }

    return  NULL;
}


