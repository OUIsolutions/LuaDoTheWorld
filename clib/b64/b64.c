
LuaCEmbedResponse  * base64_encode_file(LuaCEmbed *args){
    char *source = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    char * b64_string =  dtw.convert_binary_file_to_base64(source);
    if(!b64_string){
        char *formmated  = private_LuaCembed_format(FILE_NOT_FOUND,source);
        LuaCEmbedResponse  *response = lua.response.send_error(formmated);
        free(formmated);
        return response;
    }
    LuaCEmbedResponse  *response = lua.response.send_str(b64_string);
    free(b64_string);
    return response;
}


LuaCEmbedResponse  * base64_decode(LuaCEmbed *args){
    char *source = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    long size;
    unsigned char *content = dtw.base64_decode(source,&size);
    bool is_binary = false;
    for(long  i = 0; i < size; i++){
        if(content[i] == '\0'){
            is_binary = true;
            break;
        }
    }

    if(!is_binary){
        content[size] = '\0';
        LuaCEmbedResponse  *response = lua.response.send_str((char*)content);
        free(content);
        return response;
    }

    LuaCEmbedTable * table = create_bytes(args,content,size);
    return  lua.response.send_table(table);
}

LuaCEmbedResponse  * base64_encode(LuaCEmbed *args){
    int args_size = lua.args.size(args);
    if(args_size == 0){
        return  lua.response.send_error(ARGUMENT_NOT_PROVIDED);
    }

    int arg_type = lua.args.get_type(args,0);

    if(arg_type == lua.types.STRING){
        unsigned char *content =(unsigned char*)lua.args.get_str(args,0);
        long size = (long)strlen((char*)content);
        char *converted = dtw.base64_encode(content,size);
        LuaCEmbedResponse *response = lua.response.send_str(converted);
        free(converted);
        return response;
    }
    else if(arg_type == lua.types.NUMBER){
        double value = lua.args.get_double(args,0);
        char formatted[20] = {0};
        double rest = value - (double)(long ) value;
        if(rest == 0){
            sprintf(formatted,"%ld",(long)value);
        }
        else{
            sprintf(formatted,"%lf",value);
        }
        long content_size = (long)strlen(formatted);
        char *converted = dtw.base64_encode((unsigned char*)formatted, content_size);
        LuaCEmbedResponse *response = lua.response.send_str(converted);
        free(converted);
        return response;
    }
    else if(arg_type == lua.types.BOOL){
        bool content  = lua.args.get_bool(args,1);
        const char *formatted = content ? "true":"false";
        long content_size = (long) strlen(formatted);
        char *converted = dtw.base64_encode((unsigned char*)formatted, content_size);
        LuaCEmbedResponse *response = lua.response.send_str(converted);
        free(converted);
        return response;
    }
    else if(arg_type == lua.types.TABLE){
        LuaCEmbedTable * bytes = lua.args.get_table(args,1);
        LuaCEmbedResponse  *possible_error = ensure_table_type(bytes,BYTE_TYPE,BYTE_STRING);
        if(possible_error){
            return possible_error;
        }
        long content_size = lua.tables.get_long_prop(bytes,SIZE);
        unsigned  char * content = (unsigned  char *)lua.tables.get_long_prop(bytes,CONTENT_POINTER);
        char *converted = dtw.base64_encode(content, content_size);
        LuaCEmbedResponse *response = lua.response.send_str(converted);
        free(converted);
        return response;
    }

    char *error = private_LuaCembed_format(NOT_WRITEBLE_ELEMENT,lua.convert_arg_code(arg_type));
    LuaCEmbedResponse *response = lua.response.send_error(error);
    free(error);
    return response;
}

