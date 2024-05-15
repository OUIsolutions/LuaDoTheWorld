

LuaCEmbedResponse  * add_schema_primary_keys(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * schema_new_insertion(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * get_resource_by_name_id(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * dangerous_rename_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * commit_schema(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * delete_schema(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_find_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_count_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_map_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_each(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedTable  * raw_create_schema(LuaCEmbed *args,DtwSchema *schema);

LuaCEmbedResponse * create_schema(LuaCEmbed *args);
