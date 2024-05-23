


LuaCEmbedResponse  * Resource_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * get_resource_by_name_id(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * dangerous_rename_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);



LuaCEmbedResponse * schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_find_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_count_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_map_resource(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * schema_each(LuaCEmbedTable *self,LuaCEmbed *args);



LuaCEmbedResponse * resource_to_string(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_to_number(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_to_boolean(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * private_resource_sub_resource_raw(LuaCEmbedTable  *self, LuaCEmbed *args,const char *src);

LuaCEmbedResponse * resource_sub_resource_index(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_method(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_next(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_now(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_now_in_unix(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_value(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_value_from_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_set_value(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_commit(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_destroy(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_foreach(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_list(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * free_resource(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * unload_resurce(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * lock_resource(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * unlock_resource(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * resource_get_path(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_get_dir(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_get_name(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_get_name_without_extension(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_get_extension(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_set_extension(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_set_value_in_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_new_schema(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedTable *raw_create_resource(LuaCEmbed *args,DtwResource *resource);

LuaCEmbedResponse * create_resource(LuaCEmbed *args);