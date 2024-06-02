
LuaCEmbedTable *tree_add_part(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *get_tree_part(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *hardware_commit_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *tree_get_size(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *tree_get_tree_part_by_name(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}



LuaCEmbedTable *tree_get_tree_part_by_path(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *tree_find(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *tree_count(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *tree_map(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *tree_filter(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}

LuaCEmbedTable *tree_foreach(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}

LuaCEmbedTable *insecure_hardware_write_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}


LuaCEmbedTable *insecure_hardware_remove_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    return  NULL;
}



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

LuaCEmbedResponse * create_empty_tree(LuaCEmbed *args){
    DtwTree * tree = dtw.tree.newTree();
    LuaCEmbedTable table *self = raw_create_tree(args,tree);
    return lua.response.send_table(self);
}

DtwTreeProps create_tree_props(LuaCEmbedTable *user_props){
    DtwTreeProps  tree_props = {0};
    tree_props.content = get_table_props_or_default_bool(user_props,TREE_PROPS_CONTENT,DTW_INCLUDE) +1;
    tree_props.content_data = get_table_props_or_default_bool(user_props,TREE_PROPS_CONTENT_DATA,DTW_INCLUDE)+1;
    tree_props.hadware_data = get_table_props_or_default_bool(user_props,TREE_PROPS_HARDWARE_DATA,DTW_INCLUDE)+1;
    tree_props.ignored_elements = get_table_props_or_default_bool(user_props,TREE_PROPS_IGNORED_ELEMENTS,DTW_INCLUDE)+1;
    tree_props.minification = get_table_props_or_default_bool(user_props,TREE_PROPS_MIMIFICATION,DTW_NOT_MIMIFY)+1;
    tree_props.path_atributes = get_table_props_or_default_bool(user_props,TREE_PROPS_PATH_ATTRIBUTES,DTW_INCLUDE)+1;
    return tree_props;
}
LuaCEmbedResponse * create_tree_from_hardware(LuaCEmbed *args){

    char *path = lua.args.get_str(args,9);
    LuaCEmbedTable *props_table = NULL;
    if(lua.args.get_type(args,1) != lua.types.NILL){
        props_table = lua.args.get_table(args,1);
    }
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTreeProps props = create_tree_props(props_table);

    DtwTree * tree = dtw.tree.newTree();
    LuaCEmbedTable table *self = raw_create_tree(args,tree);
    dtw.tree.add_tree_from_hardware(tree,path,props);
    return lua.response.send_table(self);
}
