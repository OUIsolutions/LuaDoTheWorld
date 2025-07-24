//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.type.h"
//silver_chain_scope_end

LuaCEmbedResponse * transaction_commit(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse * transaction_delete(LuaCEmbedTable *self,LuaCEmbed *args);

void  private_transaction_add_base_methods(LuaCEmbedTable *self,DtwTransaction *transaction);


LuaCEmbedResponse * transaction_new_transaction(LuaCEmbed *args);