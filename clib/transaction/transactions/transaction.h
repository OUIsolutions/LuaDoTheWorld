


LuaCEmbedResponse * transaction_write(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * transaction_remove_any(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * transaction_copy_any(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * transaction_move_any(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * transaction_commit(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * transaction_dumps_to_json_file(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * transaction_dumps_to_json_string(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse * transaction_delete(LuaCEmbedTable *self,LuaCEmbed *args);

void  private_transaction_add_base_methods(LuaCEmbedTable *self,DtwTransaction *transaction);


LuaCEmbedResponse * create_empty_transaction_from_json_string(LuaCEmbed *args);

LuaCEmbedResponse * create_empty_transaction_from_json_file(LuaCEmbed *args);

LuaCEmbedResponse * create_empty_transacton(LuaCEmbed *args);