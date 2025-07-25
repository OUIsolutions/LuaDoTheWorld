//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.type.h"
//silver_chain_scope_end

void ldtw_serialize_str(privateLuaDtwStringAppender *appender, unsigned char *str, long size);

void ldtw_serialize_first_value_of_table( privateLuaDtwStringAppender *appender ,LuaCEmbedTable *entries);

void ldtw_serialize_table(privateLuaDtwStringAppender *appender,LuaCEmbedTable *table);

LuaCEmbedResponse *ldtw_serialize_var(LuaCEmbed *args);

LuaCEmbedResponse *ldtw_interpret_serialized_var(LuaCEmbed *args);