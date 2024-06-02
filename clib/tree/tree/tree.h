
LuaCEmbedResponse *new_tree_part(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *new_tree_part_loading(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *new_tree_part_empty(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *get_tree_part_by_index(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *hardware_commit_tree(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *tree_get_size(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse *tree_get_tree_part_by_name(LuaCEmbedTable *self, LuaCEmbed *args);



LuaCEmbedResponse *tree_get_tree_part_by_path(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse *tree_find(LuaCEmbedTable *self, LuaCEmbed *args);



LuaCEmbedResponse *tree_count(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *tree_map(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse *tree_foreach(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse *insecure_hardware_write_tree(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse *insecure_hardware_remove_tree(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *tree_dump_to_json_string(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse *tree_dump_to_json_file(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable * raw_create_tree(LuaCEmbed *args,DtwTree *tree);


LuaCEmbedResponse * create_empty_tree(LuaCEmbed *args);

DtwTreeProps create_tree_props(LuaCEmbedTable *user_props);

LuaCEmbedResponse * create_tree_from_hardware(LuaCEmbed *args);

LuaCEmbedResponse * create_tree_from_json_tree_string(LuaCEmbed *args);

LuaCEmbedResponse * create_tree_from_json_tree(LuaCEmbed *args);
