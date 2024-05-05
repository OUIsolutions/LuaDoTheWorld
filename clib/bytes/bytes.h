
LuaCEmbedResponse  *delete_bytes(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *get_byte_at(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedTable * create_bytes(LuaCEmbed  *args,unsigned  char *content,long size);


LuaCEmbedTable * create_bytes_ref(LuaCEmbed  *args,unsigned  char *content,long size);

LuaCEmbedResponse * is_byte(LuaCEmbed  *args);
