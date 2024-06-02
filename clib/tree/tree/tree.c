
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


LuaCEmbedTable * raw_create_tree(LuaCEmbed *args,DtwTree *tree){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,TREE_POINTER,(long long)tree);
    lua.tables.set_method(self,ADD_TREE_PART_METHOD,tree_add_part);
    lua.tables.set_method(self,GET_TREE_PART_BY_INDEX_METHOD,get_tree_part);
    lua.tables.set_method(self,INSECURE_HARDWARE_WRITE_TREE,insecure_hardware_write_tree);
    lua.tables.set_method(self,INSECURE_HARDWARE_REMOVE_TREE,insecure_hardware_remove_tree);
    lua.tables.set_method(self,COMMIT_METHOD,hardware_commit_tree);
    lua.tables.set_method(self,GET_SIZE_METHOD,tree_get_size);
    lua.tables.set_method(self,GET_TREE_PART_BY_NAME,tree_get_tree_part_by_name);
    lua.tables.set_method(self,GET_TREE_PART_BY_PATH,tree_get_tree_part_by_path);
    lua.tables.set_method(self,FIND_METHOD,tree_find);
    lua.tables.set_method(self,COUNT_METHOD,tree_count);
    lua.tables.set_method(self,MAP_METHOD,tree_map);
    lua.tables.set_method(self,EACH_METHOD,tree_foreach);
    return self;
}

LuaCEmbedResponse * create_tree(LuaCEmbed *self);