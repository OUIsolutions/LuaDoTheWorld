
LuaCEmbedResponse * delete_resource(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
}

LuaCEmbedResponse * resource_to_string(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)lua.tables.get_long_prop(self,RESOURCE_POINTER);
    char *value = dtw.resource.get_string(resource);
}


LuaCEmbedResponse * createResource(LuaCEmbed *args){
    char *folder = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_message = lua.get_error_message(args);
        return  lua.response.send_error(error_message);
    }
    DtwResource *resource = new_DtwResource(folder);
    LuaCEmbedTable * self  = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(self,RESOURCE_POINTER,(long)resource);
    lua.tables.set_method(self,DELETE_METHOD,delete_resource);

}