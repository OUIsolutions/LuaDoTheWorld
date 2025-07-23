//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedResponse  *action_transaction_get_transaction_type_code(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_transaction_type(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_content(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_set_content(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_set_source(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_set_dest(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_source(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_dest(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedTable *raw_create_action_transaction(LuaCEmbed *args,DtwActionTransaction *transaction);
