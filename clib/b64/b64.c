
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

    if(is_binary){
        LuaCEmbedTable * table = create_bytes(args,content,size);
        return  lua.response.send_table(table);
    }
    
    content[size] = '\0';
    LuaCEmbedResponse  *response = lua.response.send_str((char*)content);
    free(content);
    return response;
}

LuaCEmbedResponse  * base64_encode(LuaCEmbed *args){
    Writeble write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }

    char *created = dtw.base64_encode(write_obj.content,write_obj.size);
    Writeble_free(&write_obj);
    LuaCEmbedResponse *response = lua.response.send_str(created);
    free(created);
    return response;
}

