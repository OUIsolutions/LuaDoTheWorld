//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



void ldtw_serialize_str(privateLuaDtwStringAppender *appender,unsigned char *str,long size){
    privateLuaDtwStringAppender_append(appender,"'");

    for(int i = 0; i < size; i++){
        privateLuaDtwStringAppender_append_fmt(appender,"\\%d", (unsigned char)str[i]);
    }

    privateLuaDtwStringAppender_append(appender,"'");

}
LuaCEmbedResponse *ldtw_serialize_var(LuaCEmbed *args){


    privateLuaDtwStringAppender *appender = newprivateLuaDtwStringAppender();
    privateLuaDtwStringAppender_append(appender,"(function()\n");
    int type  = LuaCEmbed_get_arg_type(args, 0);
    if(type == LUA_CEMBED_STRING){
        lua_Integer size;
        unsigned char *str = LuaCEmbed_get_raw_str_arg(args, &size, 0);
        privateLuaDtwStringAppender_append(appender, "return ");
        ldtw_serialize_str(appender, str, size);
    }
    if(type == LUA_CEMBED_NUMBER){
        double int_val = LuaCEmbed_get_double_arg(args, 0);
        privateLuaDtwStringAppender_append_fmt(appender, "return %f", int_val);
    }
    
    if(type == LUA_CEMBED_BOOL){
        bool bool_val = LuaCEmbed_get_bool_arg(args, 0);
        privateLuaDtwStringAppender_append_fmt(appender, "return %s", bool_val ? "true" : "false");
    }
    
    if(type == LUA_CEMBED_NIL){
        privateLuaDtwStringAppender_append(appender, "return nil");
    }

    if(type == LUA_CEMBED_TABLE){
        privateLuaDtwStringAppender_append(appender, "return {}");
    }

    privateLuaDtwStringAppender_append(appender,"\nend)();");

    LuaCEmbedResponse *response = LuaCEmbed_send_str(appender->buffer);
    privateLuaDtwStringAppender_free(appender);
    return response;
}