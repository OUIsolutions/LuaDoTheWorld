LuaCEmbedResponse *set_randonizer_seed_seed(LuaCEmbedTable *self,LuaCEmbed *args) {

    DtwRandonizer *random = (DtwRandonizer*)LuaCembedTable_get_long_prop(self,RANDONIZER_POINTER);
    long seed = LuaCEmbed_get_long_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *msg = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(msg);
    }
    random->time_seed = seed;
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *set_randonizer_time_seed(LuaCEmbedTable *self,LuaCEmbed *args) {

    DtwRandonizer *random = (DtwRandonizer*)LuaCembedTable_get_long_prop(self,RANDONIZER_POINTER);
    long seed = LuaCEmbed_get_long_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *msg = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(msg);
    }
    random->seed = seed;
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *generate_randonizer_token(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwRandonizer *random = (DtwRandonizer*)LuaCembedTable_get_long_prop(self,RANDONIZER_POINTER);
    long size = LuaCEmbed_get_long_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *msg = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(msg);
    }
    char *token = DtwRandonizer_generate_token(random,size);
    LuaCEmbedResponse *response = LuaCEmbed_send_str(token);
    free(token);
    return response;
}
LuaCEmbedResponse *delete_randonizer(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwRandonizer *random = (DtwRandonizer*)LuaCembedTable_get_long_prop(self,RANDONIZER_POINTER);
    DtwRandonizer_free(random);
    return NULL;
}
LuaCEmbedResponse *create_randonizer(LuaCEmbed *args) {
    DtwRandonizer *random = newDtwRandonizer();
    LuaCEmbedTable *self =  LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(self,RANDONIZER_POINTER,(long long)random);
    LuaCEmbedTable_set_method(self,SET_RANDONIZER_SEED_METHOD,set_randonizer_seed_seed);
    LuaCEmbedTable_set_method(self,SET_RANDONIZER_TIME_SEED_METHOD,set_randonizer_time_seed);
    LuaCEmbedTable_set_method(self,GENERATE_RANDONIZER_TOKEN,generate_randonizer_token);
    LuaCEmbedTable_set_method(self,DELETE_METHOD,delete_randonizer);
    return LuaCEmbed_send_table(self);
}