
LuaCEmbedTable *tree_add_part(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *get_tree_part(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *hardware_commit_tree(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_get_size(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_get_tree_part_by_name(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_get_tree_part_by_path(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_find(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_count(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_map(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_filter(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *tree_foreach(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *insecure_hardware_write_tree(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable *insecure_hardware_remove_tree(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable * raw_create_tree(LuaCEmbed *args,DtwTree *tree);

LuaCEmbedResponse * create_empty_tree(LuaCEmbed *args);

LuaCEmbedResponse * create_tree_from_hardware(LuaCEmbed *args);

DtwTreeProps create_tree_props(LuaCEmbedTable *user_props);