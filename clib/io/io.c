

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

    int size;

}
