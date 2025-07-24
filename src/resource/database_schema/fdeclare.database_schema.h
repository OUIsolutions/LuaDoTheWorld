//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.type.h"
//silver_chain_scope_end


LuaCEmbedResponse * database_schema_set_index_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * database_schema_set_value_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * database_schema_add_sub_schema(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedTable * raw_create_database_schema(LuaCEmbed *args,DtwDatabaseSchema *database_schema);