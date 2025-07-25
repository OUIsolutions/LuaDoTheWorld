//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.type.h"
//silver_chain_scope_end



LuaCEmbedResponse * resource_get_path(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_rename(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_try_rename(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * free_resource(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * resource_is_blob(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_has_value(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_get_type(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_set_value(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_try_set_value(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_commit(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_destroy(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_try_destroy(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * unload_resurce(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * lock_resource(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * unlock_resource(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse *resource_get_transaction(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_set_value_in_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_try_set_value_in_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedTable *raw_create_resource(LuaCEmbed *args,DtwResource *resource);

LuaCEmbedResponse * create_resource(LuaCEmbed *args);