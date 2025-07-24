//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.type.h"
//silver_chain_scope_end



LuaCEmbedResponse * tree_part_get_value(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_exist_in_hardware(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_exis(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse * tree_part_to_string(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *tree_part_is_blob(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse * tree_part_set_value(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_hardware_remove(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_hardware_write(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_hardware_modify(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_get_content_sha(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_unload_content(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * tree_part_load_content(LuaCEmbedTable *self,LuaCEmbed *args);



LuaCEmbedTable * create_tree_part_reference(LuaCEmbed *args,DtwTreePart *part);
