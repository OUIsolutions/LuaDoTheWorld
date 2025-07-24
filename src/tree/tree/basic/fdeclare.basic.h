//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.type.h"
//silver_chain_scope_end


LuaCEmbedResponse *hardware_commit_tree(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *tree_get_size(LuaCEmbedTable *self, LuaCEmbed *args);




LuaCEmbedResponse *insecure_hardware_write_tree(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse *insecure_hardware_remove_tree(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedTable * raw_create_tree(LuaCEmbed *args,DtwTree *tree);


LuaCEmbedResponse * create_empty_tree(LuaCEmbed *args);

DtwTreeProps create_tree_props(LuaCEmbedTable *user_props);

LuaCEmbedResponse * tree_delete(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * create_tree_fro_hardware(LuaCEmbed *args);

LuaCEmbedResponse * add_tree_fro_hardware(LuaCEmbedTable *self,LuaCEmbed *args);