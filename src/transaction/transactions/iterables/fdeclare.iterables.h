//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedResponse  * transaction_list(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse  * transaction_index(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * transaction_foreach(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * transaction_filter(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * transaction_map(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * transaction_find(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * transaction_count(LuaCEmbedTable *self,LuaCEmbed *args);
