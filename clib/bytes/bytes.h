
LuaCEmbedResponse  *delete_bytes(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *private_get_bytes_at(LuaCEmbedTable *self, long index);

LuaCEmbedResponse  *get_byte_at_index(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  *get_byte_at_method(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedTable * create_bytes(LuaCEmbed  *args,unsigned  char *content,long size);


LuaCEmbedTable * create_bytes_ref(LuaCEmbed  *args,unsigned  char *content,long size);

LuaCEmbedResponse * is_byte(LuaCEmbed  *args);
