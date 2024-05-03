

LuaCEmbedResponse * resource_to_string(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_to_number(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_to_boolean(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_value(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_set_value(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * delete_resource(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedTable *raw_create_resource(LuaCEmbed *args,DtwResource *resource);

LuaCEmbedResponse * create_resource(LuaCEmbed *args);