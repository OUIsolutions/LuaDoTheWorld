

LuaCEmbedResponse * tree_part_get_value(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);

    if(self_part->content){
        return lua.response.send_raw_string((char*)self_part->content,self_part->content_size);
    }
    return NULL;
}

LuaCEmbedResponse * tree_part_to_string(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);

    if(self_part->content){
        return lua.response.send_raw_string((char*)self_part->content,self_part->content_size);
    }
    return lua.response.send_str(dtw.path.get_path(self_part->path));
}

LuaCEmbedResponse * tree_part_set_value(LuaCEmbedTable *self,LuaCEmbed *args){
    Writeble  write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.set_any_content(self_part,write_obj.content,write_obj.size,write_obj.is_binary);
    return lua.response.send_table(self);
}


LuaCEmbedResponse * tree_part_hardware_remove(LuaCEmbedTable *self,LuaCEmbed *args){
    bool set_as_action = true;
    if(lua.args.get_type(args,0) != lua.types.NILL){
        set_as_action = lua.args.get_bool(args,0);
    }

    if(lua.has_errors(args)){
        const char *error_menssage = lua.get_error_message(args);
        return lua.response.send_error(error_menssage);
    }

    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.hardware_remove(self_part,set_as_action);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * tree_part_hardware_write(LuaCEmbedTable *self,LuaCEmbed *args){

    bool set_as_action = true;
    if(lua.args.get_type(args,0) != lua.types.NILL){
        set_as_action = lua.args.get_bool(args,0);
    }

    if(lua.has_errors(args)){
        const char *error_menssage = lua.get_error_message(args);
        return lua.response.send_error(error_menssage);
    }


    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.hardware_write(self_part,set_as_action);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * tree_part_hardware_modify(LuaCEmbedTable *self,LuaCEmbed *args){

    bool set_as_action = true;
    if(lua.args.get_type(args,0) != lua.types.NILL){
        set_as_action = lua.args.get_bool(args,0);
    }

    if(lua.has_errors(args)){
        const char *error_menssage = lua.get_error_message(args);
        return lua.response.send_error(error_menssage);
    }

    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.hardware_modify(self_part,set_as_action);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * tree_part_get_content_sha(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    if(self_part->current_sha){
        return lua.response.send_str(self_part->current_sha);
    }
    return NULL;
}


LuaCEmbedResponse * tree_part_unload_content(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.free_content(self_part);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * tree_part_load_content(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.load_content_from_hardware(self_part);
    return lua.response.send_table(self);
}

LuaCEmbedResponse *tree_part_is_blob(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    return  lua.response.send_bool(self_part->is_binary);
}

LuaCEmbedTable * create_tree_part_reference(LuaCEmbed *args,DtwTreePart *part){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,TREE_PART_POINTER,(long long)part);
    lua.tables.set_long_prop(self,DTW_TYPE,DTW_TREE_PART_TYPE);
    LuaCEmbedTable *path = create_path_reference(args,part->path);
    lua.tables.set_sub_table_prop(self,PATH_PROPS,path);
    lua.tables.set_method(self,GET_VALUE_METHOD,tree_part_get_value);
    lua.tables.set_method(self,SET_VALUE_METHOD,tree_part_set_value);
    lua.tables.set_method(self,HARDWARE_REMOVE_METHOD,tree_part_hardware_remove);
    lua.tables.set_method(self,HARDWARE_MODIFY_METHOD,tree_part_hardware_modify);
    lua.tables.set_method(self,HARWARE_WRITE_METHOD,tree_part_hardware_write);
    lua.tables.set_method(self,GET_SHA_METHOD,tree_part_get_content_sha);
    lua.tables.set_method(self,UNLOAD_METHOD,tree_part_unload_content);
    lua.tables.set_method(self,TO_STRING_METHOD,tree_part_to_string);
    lua.tables.set_method(self,IS_BLOB_FUNC,tree_part_is_blob);
    lua.tables.set_method(self,LOAD_METHOD,tree_part_load_content);
    return self;
}



