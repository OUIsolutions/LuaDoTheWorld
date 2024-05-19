


LuaCEmbedResponse * tree_part_set_value(LuaCEmbedTable *self,LuaCEmbed *args){
    Writeble  write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.set_any_content(tree_part,write_obj.content,write_obj.size,write_obj.is_binary);
    return  lua.response.send_table(self);
}


LuaCEmbedResponse * treepart__part_get_value(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.tree.part.load_content_from_hardware(tree_part);
    dtw.tree.part.load_content_from_hardware(tree_part);
    if(!tree_part->content){
        DtwTreePart_load_content_from_hardware(tree_part);
    }
    if(!tree_part->content){
        char *path = dtw.path.get_path(tree_part->path);
        return lua.response.send_str(path);
    }
    if(tree_part->is_binary){
        unsigned  char *content  = dtw.tree.part.get_content_binary_by_reference(tree_part);
        LuaCEmbedTable *response = create_bytes_ref(args,content,(long)tree_part->content_size);
        return lua.response.send_table(response);
    }

    char * value = dtw.tree.part.get_content_string_by_reference(tree_part);
    return lua.response.send_str(value);

}

LuaCEmbedResponse * tree_part_get_name(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    char *value = dtw.path.get_full_name(tree_part->path);
    return lua.response.send_str(value);
}

LuaCEmbedResponse * tree_part_get_name_without_extension(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    char *value = dtw.path.get_name(tree_part->path);
    return lua.response.send_str(value);
}

LuaCEmbedResponse * tree_part_get_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    char *value = dtw.path.get_dir(tree_part->path);
    return lua.response.send_str(value);
}

LuaCEmbedResponse * tree_part_get_path(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    char *value = dtw.path.get_path(tree_part->path);
    return lua.response.send_str(value);
}

LuaCEmbedResponse * tree_part_set_name(LuaCEmbedTable *self,LuaCEmbed *args){
    char *name = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.path.set_full_name(tree_part->path,name);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * tree_part_set_name_without_extension(LuaCEmbedTable *self,LuaCEmbed *args){
    char *name = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.path.set_name(tree_part->path,name);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * tree_part_set_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    char *dir = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);

    dtw.path.set_dir(tree_part->path,dir);
    return lua.response.send_table(self);
}

LuaCEmbedResponse * tree_part_set_path(LuaCEmbedTable *self,LuaCEmbed *args){
    char *path = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error = lua.get_error_message(args);
        return  lua.response.send_error(error);
    }
    DtwTreePart *tree_part = (DtwTreePart*)lua.tables.get_long_prop(self,TREE_PART_POINTER);
    dtw.path.set_path(tree_part->path,path);
    return lua.response.send_table(self);
}


LuaCEmbedTable  * tree_part_raw_create_table(LuaCEmbed *args, DtwTreePart *tree_part){
    LuaCEmbedTable *self = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,TREE_PART_POINTER,(long)tree_part);
    return self;
}


LuaCEmbedResponse * create_tree_part(LuaCEmbed *args);
