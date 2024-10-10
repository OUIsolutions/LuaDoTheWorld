
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.macros.h"
//silver_chain_scope_end

LuaCEmbedResponse * try_create_tree_from_json_tree_string(LuaCEmbed *args);

LuaCEmbedResponse * create_tree_from_json_tree_string(LuaCEmbed *args);

LuaCEmbedResponse * create_tree_from_json_tree_file(LuaCEmbed *args);

LuaCEmbedResponse * try_create_tree_from_json_tree_file(LuaCEmbed *args);

LuaCEmbedResponse *tree_dump_to_json_string(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *tree_dump_to_json_file(LuaCEmbedTable *self, LuaCEmbed *args);