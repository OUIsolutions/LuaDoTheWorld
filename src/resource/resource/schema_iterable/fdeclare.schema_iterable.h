//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedResponse * schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * try_schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_find_resource(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse * schema_count_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_filter_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_map_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_schema_each(LuaCEmbedTable *self, LuaCEmbed *args);
