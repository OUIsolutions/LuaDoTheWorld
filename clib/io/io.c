

LuaCEmbedResponse  * load_file(LuaCEmbed *args){
    char *filename = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    int type = dtw.entity_type(filename);
    if(type != DTW_FILE_TYPE ){
        return NULL;
    }

    long  size;
    bool is_binary;
    unsigned  char *content = dtw.load_any_content(filename,&size,&is_binary);
    if(!is_binary){
        LuaCEmbedResponse  * response = lua.response.send_str((const char*)content);
        free(content);
        return response;
    }
    LuaCEmbedTable * bytes = create_bytes(args,content,size);
    return lua.response.send_table(bytes);
}

LuaCEmbedResponse  * write_file(LuaCEmbed *args){
    char *filename = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    long total_args = lua.args.size(args);
    if(total_args == 0){
        dtw_write_string_file_content(filename,"");
        return NULL;
    }
    int type_to_write = lua.args.get_type(args,1);
    if(type_to_write == lua.types.STRING){
        char *content = lua.args.get_str(args,1);
        dtw_write_string_file_content(filename,content);
        return NULL;
    }
    if(type_to_write == lua.types.NUMBER){
        double content = lua.args.get_double(args,1);
        double rest = content - (double)(long ) content;
        if(rest == 0){
            dtw.write_long_file_content(filename,(long)content);
        }
        else{
            dtw.write_double_file_content(filename,content);
        }
        return NULL;
    }
    if(type_to_write == lua.types.BOOL){
        bool content  = lua.args.get_bool(args,1);
        const char *converted = content ? "true":"false";
        dtw_write_string_file_content(filename,converted);
    }
    if(type_to_write == lua.types.TABLE){
        LuaCEmbedTable * bytes = lua.args.get_table(args,1);
        LuaCEmbedResponse  *possible_error = ensure_table_type(bytes,BYTE_TYPE,BYTE_STRING);
        if(possible_error){
            return possible_error;
        }
        long size = lua.tables.get_long_prop(bytes,SIZE);
        unsigned  char * content = (unsigned  char *)lua.tables.get_long_prop(bytes,CONTENT_POINTER);
        dtw_write_any_content(filename,content,size);
    }
    return  NULL;
}
