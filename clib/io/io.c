

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
    bool writed = false;
    long total_args = lua.args.size(args);
    if(total_args == 0){
       writed = dtw.write_string_file_content(filename,"");
        return lua.response.send_bool(writed);
    }

    int type_to_write = lua.args.get_type(args,1);
    if(type_to_write == lua.types.STRING){
        char *content = lua.args.get_str(args,1);
        writed = dtw.write_string_file_content(filename,content);
    }

    else if(type_to_write == lua.types.NUMBER){
        double content = lua.args.get_double(args,1);
        double rest = content - (double)(long ) content;
        if(rest == 0){
            char formatted[20] = {0};
            sprintf(formatted,"%ld",(long)content);
            writed = dtw.write_string_file_content(filename,formatted);
        }
        else{
            char formatted[20] = {0};
            sprintf(formatted,"%lf",content);
            writed = dtw.write_string_file_content(filename,formatted);
        }

    }
    else if(type_to_write == lua.types.BOOL){
        bool content  = lua.args.get_bool(args,1);
        const char *converted = content ? "true":"false";
        writed = dtw_write_string_file_content(filename,converted);
    }

    else if(type_to_write == lua.types.TABLE){
        LuaCEmbedTable * bytes = lua.args.get_table(args,1);
        LuaCEmbedResponse  *possible_error = ensure_table_type(bytes,BYTE_TYPE,BYTE_STRING);
        if(possible_error){
            return possible_error;
        }
        long size = lua.tables.get_long_prop(bytes,SIZE);
        unsigned  char * content = (unsigned  char *)lua.tables.get_long_prop(bytes,CONTENT_POINTER);
        writed =dtw_write_any_content(filename,content,size);
    }
    else{
        char *error = private_LuaCembed_format(NOT_WRITEBLE_ELEMENT,lua.convert_arg_code(type_to_write));
        LuaCEmbedResponse *response = lua.response.send_error(error);
        free(error);
        return response;
    }
    return  lua.response.send_bool(writed);
}

LuaCEmbedResponse  * copy_any_overwriting(LuaCEmbed *args){
    char *source = lua.args.get_str(args,0);
    char *dest = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }

    bool writed = dtw.copy_any(source,dest,DTW_NOT_MERGE);
    return lua.response.send_bool(writed);
}


LuaCEmbedResponse  * copy_any_merging(LuaCEmbed *args){
    char *source = lua.args.get_str(args,0);
    char *dest = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }

    bool writed = dtw.copy_any(source,dest,DTW_MERGE);
    return lua.response.send_bool(writed);
}

LuaCEmbedResponse  * move_any_overwriting(LuaCEmbed *args){
    char *source = lua.args.get_str(args,0);
    char *dest = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    bool writed = dtw.move_any(source,dest,DTW_NOT_MERGE);
    return lua.response.send_bool(writed);
}
LuaCEmbedResponse  * move_any_merging(LuaCEmbed *args){
    char *source = lua.args.get_str(args,0);
    char *dest = lua.args.get_str(args,1);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    bool writed = dtw.move_any(source,dest,DTW_MERGE);
    return lua.response.send_bool(writed);
}


LuaCEmbedResponse  * remove_any(LuaCEmbed *args){
    char *source = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    bool writed = dtw.remove_any(source);
    return lua.response.send_bool(writed);
}


