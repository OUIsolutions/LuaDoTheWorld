
LuaCEmbedResponse *new_tree_part(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = lua.args.get_str(args,0);

    LuaCEmbedTable *props_table = NULL;
    if(lua.args.get_type(args,1) != lua.types.NILL){
        props_table = lua.args.get_table(args,1);
    }
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTreeProps props = create_tree_props(props_table);
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    DtwTreePart *tree_part = dtw.tree.part.newPartLoading(path);
    dtw.tree.add_tree_part_getting_owenership(self_tree,tree_part);
    LuaCEmbedTable *tree_part_table = create_tree_part_reference(args,tree_part);
    return lua.response.send_table(tree_part_table);
}

LuaCEmbedResponse *new_tree_part_loading(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    DtwTreePart *tree_part = dtw.tree.part.newPartLoading(path);
    dtw.tree.add_tree_part_getting_owenership(self_tree,tree_part);
    LuaCEmbedTable *tree_part_table = create_tree_part_reference(args,tree_part);
    return lua.response.send_table(tree_part_table);
}

LuaCEmbedResponse *new_tree_part_empty(LuaCEmbedTable *self, LuaCEmbed *args){

    char *path = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    DtwTreePart *tree_part = dtw.tree.part.newPartEmpty(path);
    dtw.tree.add_tree_part_getting_owenership(self_tree,tree_part);
    LuaCEmbedTable *tree_part_table = create_tree_part_reference(args,tree_part);
    return lua.response.send_table(tree_part_table);
}

LuaCEmbedResponse *get_tree_part_by_index(LuaCEmbedTable *self, LuaCEmbed *args){

    long index = lua.args.get_long(args,0)-1;
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    if(index>=self_tree->size){
        return NULL;
    }

    LuaCEmbedTable *result  = create_tree_part_reference(args,self_tree->tree_parts[index]);
    return  lua.response.send_table(result);
}



LuaCEmbedResponse *hardware_commit_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    dtw.tree.hardware_commit_tree(self_tree);
    return  lua.response.send_table(self);
}


LuaCEmbedResponse *tree_get_size(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    return lua.response.send_long(self_tree->size);
}


LuaCEmbedResponse *tree_get_tree_part_by_name(LuaCEmbedTable *self, LuaCEmbed *args){
    char *name = lua.args.get_str(args,0);

    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    DtwTreePart * possible = dtw.tree.find_tree_part_by_name(self_tree,name);
    if(possible == NULL){
        return NULL;
    }
    LuaCEmbedTable *created_table = create_tree_part_reference(args,possible);
    return lua.response.send_table(created_table);
}



LuaCEmbedResponse *tree_get_tree_part_by_path(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = lua.args.get_str(args,0);

    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    DtwTreePart * possible = dtw.tree.find_tree_part_by_path(self_tree,path);
    if(possible == NULL){
        return NULL;
    }
    LuaCEmbedTable *created_table = create_tree_part_reference(args,possible);
    return lua.response.send_table(created_table);}


LuaCEmbedResponse *tree_find(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);

    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_call,tree_part);
        LuaCEmbedTable *response = lua.args.run_lambda(args,0,args_to_call,1);
        if(lua.has_errors(args)){
            char *error_msg = lua.get_error_message(args);
            return lua.response.send_error(error_msg);
        }
        int response_type =lua.tables.get_type_by_index(response,0);
        if(response_type != lua.types.NILL){
            bool is_the_value = lua.tables.get_bool_by_index(response,0);
            if(lua.has_errors(args)){
                char *error_msg = lua.get_error_message(args);
                return lua.response.send_error(error_msg);
            }

            if(is_the_value){
                return  lua.response.send_table(tree_part);
            }
        }
    }
    return NULL;
}


LuaCEmbedResponse *tree_count(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    long total = 0;
    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_call,tree_part);
        LuaCEmbedTable *response = lua.args.run_lambda(args,0,args_to_call,1);
        if(lua.has_errors(args)){
            char *error_msg = lua.get_error_message(args);
            return lua.response.send_error(error_msg);
        }
        int response_type =lua.tables.get_type_by_index(response,0);
        if(response_type != lua.types.NILL){
            bool is_the_value = lua.tables.get_bool_by_index(response,0);
            if(lua.has_errors(args)){
                char *error_msg = lua.get_error_message(args);
                return lua.response.send_error(error_msg);
            }

            if(is_the_value){
                total+=1;
            }
        }

    }
    return lua.response.send_long(total);
}


LuaCEmbedResponse *tree_map(LuaCEmbedTable *self, LuaCEmbed *args){

    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    LuaCEmbedTable *final_map = lua.tables.new_anonymous_table(args);

    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_call,tree_part);
        LuaCEmbedTable *response = lua.args.run_lambda(args,0,args_to_call,1);
        if(lua.has_errors(args)){
            char *error_msg = lua.get_error_message(args);
            return lua.response.send_error(error_msg);
        }
        int response_type =lua.tables.get_type_by_index(response,0);
        if(response_type!= LUA_CEMBED_NIL && response_type != LUA_CEMBED_NOT_FOUND){
            lua.tables.append_evaluation(final_map,"%s[1]",response->global_name);
        }

    }
    return lua.response.send_table(final_map);
}




LuaCEmbedResponse *tree_foreach(LuaCEmbedTable *self, LuaCEmbed *args){

    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);

    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = lua.tables.new_anonymous_table(args);
        lua.tables.append_table(args_to_call,tree_part);
        lua.args.run_lambda(args,0,args_to_call,1);
        if(lua.has_errors(args)){
            char *error_msg = lua.get_error_message(args);
            return lua.response.send_error(error_msg);
        }

    }
    return NULL;
}

LuaCEmbedResponse *insecure_hardware_write_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    dtw.tree.insecure_hardware_write_tree(self_tree);
    return lua.response.send_table(self);
}


LuaCEmbedResponse *insecure_hardware_remove_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    dtw.tree.insecure_hardware_remove_tree(self_tree);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *tree_dump_to_json_string(LuaCEmbedTable *self, LuaCEmbed *args){
    LuaCEmbedTable *props_table = NULL;
    if(lua.args.get_type(args,0) != lua.types.NILL){
        props_table = lua.args.get_table(args,0);
    }
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTreeProps props = create_tree_props(props_table);
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    char *result = dtw.tree.dumps_json_tree(self_tree,props);
    LuaCEmbedResponse *response = lua.response.send_str(result);
    free(result);
    return  response;
}

LuaCEmbedResponse *tree_dump_to_json_file(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = lua.args.get_str(args,0);
    LuaCEmbedTable *props_table = NULL;
    if(lua.args.get_type(args,1) != lua.types.NILL){
        props_table = lua.args.get_table(args,1);
    }
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }

    DtwTreeProps props = create_tree_props(props_table);
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)lua.tables.get_long_prop(self,TREE_POINTER);
    dtw.tree.dumps_json_tree_to_file(self_tree,path,props);
    return  lua.response.send_table(self);
}

LuaCEmbedTable * raw_create_tree(LuaCEmbed *args,DtwTree *tree){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,TREE_POINTER,(long long)tree);
    lua.tables.set_method(self,TREE_NEW_TREE_PART_EMPTY,new_tree_part_empty);
    lua.tables.set_method(self,TREE_NEW_TREE_PART_LOADING,new_tree_part_loading);
    lua.tables.set_method(self,GET_TREE_PART_BY_INDEX_METHOD,get_tree_part_by_index);
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
    lua.tables.set_method(self,DUMP_TO_JSON_STRING,tree_dump_to_json_string);
    lua.tables.set_method(self,DUMP_TO_JSON_FILE_METHOD,tree_dump_to_json_file);

    return self;
}

LuaCEmbedResponse * create_empty_tree(LuaCEmbed *args){
    DtwTree * tree = dtw.tree.newTree();
    LuaCEmbedTable *self = raw_create_tree(args,tree);
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
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }
    DtwTree * tree = dtw.tree.newTree();
    LuaCEmbedTable *self = raw_create_tree(args,tree);
    dtw.tree.add_tree_from_hardware(tree,path,props);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * create_tree_from_json_tree_string(LuaCEmbed *args){
    char *content = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return lua.response.send_error(error_msg);
    }
    DtwJsonTreeError *json_error =DtwJsonTreeError_validate_json_tree(content);
    if(json_error){
        LuaCEmbedResponse *response =
    }
    DtwTree *tree = dtw.tree.newTree();
    dtw.tree.loads_json_tree(tree,content);
}

LuaCEmbedResponse * create_tree_from_json_tree(LuaCEmbed *args);


