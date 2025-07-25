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
void ldtw_serialize_table(privateLuaDtwStringAppender *appender,LuaCEmbedTable *table){
    privateLuaDtwStringAppender_append(appender, " {");
    lua_Integer size = LuaCEmbedTable_get_full_size(table);
    
    bool first_element = true;
    bool has_keyed_elements = false;
    
    // First, serialize all indexed elements (array elements without keys)
    for(lua_Integer i = 0; i < size; i++){
        bool has_key = LuaCembedTable_has_key_at_index(table, i);
        if (has_key) {
            has_keyed_elements = true;
            continue;
        }
        
        if(!first_element) privateLuaDtwStringAppender_append(appender, ", ");
        first_element = false;
        
        // Serialize value
        int type = LuaCEmbedTable_get_type_by_index(table, i);
        if(type == LUA_CEMBED_STRING){
            lua_Integer str_size;
            unsigned char *str = (unsigned char*)LuaCEmbedTable_get_raw_string_by_index(table, i, &str_size);
            ldtw_serialize_str(appender, str, str_size);
        }else if(type == LUA_CEMBED_NUMBER){
            double num = LuaCEmbedTable_get_double_by_index(table, i);
            privateLuaDtwStringAppender_append_fmt(appender, "%f", num);
        }else if(type == LUA_CEMBED_BOOL){
            bool b = LuaCEmbedTable_get_bool_by_index(table, i);
            privateLuaDtwStringAppender_append(appender, b ? "true" : "false");
        }else if(type == LUA_CEMBED_NIL){
            privateLuaDtwStringAppender_append(appender, "nil");
        }else if(type == LUA_CEMBED_TABLE){
            LuaCEmbedTable *sub = LuaCEmbedTable_get_sub_table_by_index(table, i);
            ldtw_serialize_table(appender, sub);
        }else{
            privateLuaDtwStringAppender_append(appender, "nil"); // fallback for unknown types
        }
    }
    
    if(!has_keyed_elements){
        return;
    }
    
    // Collect all keys and sort them
    DtwStringArray *keys = newDtwStringArray();
    for(lua_Integer i = 0; i < size; i++){
        bool has_key = LuaCembedTable_has_key_at_index(table, i);
        if (!has_key) {
            continue;
        }
        char *key = LuaCembedTable_get_key_by_index(table, i);
        DtwStringArray_append(keys, key);
    }
    DtwStringArray_sort(keys);
    
    // Serialize sorted keyed elements
    for(int i = 0; i < keys->size; i++){
        char *key = keys->strings[i];
        
        if(!first_element) privateLuaDtwStringAppender_append(appender, ", ");
        first_element = false;
        
        privateLuaDtwStringAppender_append(appender, "[");
        ldtw_serialize_str(appender, (unsigned char*)key, strlen(key));
        privateLuaDtwStringAppender_append(appender, "] = ");
        
        int type = LuaCEmbedTable_get_type_prop(table, key);
        if(type == LUA_CEMBED_STRING){
            lua_Integer str_size;
            unsigned char *str = (unsigned char*)LuaCembedTable_get_raw_string_prop(table, key, &str_size);
            ldtw_serialize_str(appender, str, str_size);
        }else if(type == LUA_CEMBED_NUMBER){
            double num = LuaCembedTable_get_double_prop(table, key);
            privateLuaDtwStringAppender_append_fmt(appender, "%f", num);
        }else if(type == LUA_CEMBED_BOOL){
            bool b = LuaCembedTable_get_bool_prop(table, key);
            privateLuaDtwStringAppender_append(appender, b ? "true" : "false");
        }else if(type == LUA_CEMBED_NIL){
            privateLuaDtwStringAppender_append(appender, "nil");
        }else if(type == LUA_CEMBED_TABLE){
            LuaCEmbedTable *sub = LuaCEmbedTable_get_sub_table_by_key(table, key);
            ldtw_serialize_table(appender, sub);
        }else{
            privateLuaDtwStringAppender_append(appender, "nil"); // fallback for unknown types
        }
    }
    DtwStringArray_free(keys);
    
    
    privateLuaDtwStringAppender_append(appender, " }");
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
        privateLuaDtwStringAppender_append(appender, "return");
        LuaCEmbedTable *table = LuaCEmbed_get_arg_table(args, 0);
        ldtw_serialize_table(appender, table);
    }

    privateLuaDtwStringAppender_append(appender,"\nend)();");

    LuaCEmbedResponse *response = LuaCEmbed_send_str(appender->buffer);
    privateLuaDtwStringAppender_free(appender);
    return response;
}