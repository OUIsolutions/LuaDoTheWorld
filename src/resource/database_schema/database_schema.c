


LuaCEmbedResponse * database_schema_add_sub_schema(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *name = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }

    DtwDatabaseSchema *root_sschema = (DtwDatabaseSchema*)LuaCembedTable_get_long_prop(self,DATABASE_SCHEMA_POINTER);
    DtwSchema *sub_schmea = DtwDtatabaseSchema_new_subSchema(root_sschema,name);
    LuaCEmbedTable *created_table = raw_create_schema(args,sub_schmea);
    return LuaCEmbed_send_table(created_table);
}

LuaCEmbedTable * raw_create_database_schema(LuaCEmbed *args,DtwDatabaseSchema *database_schema) {
    LuaCEmbedTable *self = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(self,DATABASE_SCHEMA_POINTER,(long long)database_schema);
    LuaCEmbedTable_set_method(self,SUB_SCHEMA_METHOD,database_schema_add_sub_schema);
    return self;
}