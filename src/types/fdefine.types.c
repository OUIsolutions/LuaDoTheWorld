
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end




LuaCEmbedResponse * ensure_table_type(LuaCEmbedTable *table,int expected_type,const char *expected_type_string){

    if(LuaCEmbedTable_get_type_prop(table,DTW_TYPE) != LUA_CEMBED_NUMBER){
        char formated_error[100] = {0};
        sprintf(formated_error,NOT_EXPECTED_TYPE,expected_type_string);
        return LuaCEmbed_send_error(formated_error);
    }
    long type = LuaCembedTable_get_long_prop(table,DTW_TYPE);
    if(type !=  expected_type){
        char formated_error[100] = {0};
        sprintf(formated_error,NOT_EXPECTED_TYPE,expected_type_string);
        return LuaCEmbed_send_error(formated_error);
    }
    return NULL;
}
