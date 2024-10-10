
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedResponse * hasher_digest_file(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * hasher_digest_path(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * hasher_digest_folder_by_content(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse * hasher_digest_folder_by_last_modification(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse * hasher_get_value(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * hasher_digest(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * delete_hasher(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * create_hasher(LuaCEmbed *args);
