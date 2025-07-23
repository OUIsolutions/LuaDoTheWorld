//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedResponse  * set_schema_index_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * set_schema_value_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * add_schema_primary_keys(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * schema_add_sub_schema(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedTable  * raw_create_schema(LuaCEmbed *args,DtwSchema *schema);

