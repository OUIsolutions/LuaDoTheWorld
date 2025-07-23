//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedResponse * transaction_dumps_to_json_file(LuaCEmbedTable *self,LuaCEmbed *args);



LuaCEmbedResponse * transaction_dumps_to_json_string(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * create_transaction_from_json_string(LuaCEmbed *args);

LuaCEmbedResponse * try_create_transaction_from_json_string(LuaCEmbed *args);

LuaCEmbedResponse * create_transaction_from_json_file(LuaCEmbed *args);

LuaCEmbedResponse * try_create_transaction_from_json_file(LuaCEmbed *args);
