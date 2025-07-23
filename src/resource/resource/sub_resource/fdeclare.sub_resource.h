//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedResponse * resource_sub_resource_raw(LuaCEmbedTable  *self, LuaCEmbed *args,const char *src);

LuaCEmbedResponse * try_resource_sub_resource_raw(LuaCEmbedTable  *self, LuaCEmbed *args,const char *src);

LuaCEmbedResponse * resource_sub_resource_method(LuaCEmbedTable  *self, LuaCEmbed *args);


LuaCEmbedResponse * resource_sub_resource_index(LuaCEmbedTable  *self, LuaCEmbed *args);



LuaCEmbedResponse * try_resource_sub_resource_method(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_next(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * try_resource_sub_resource_next(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_now(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * try_resource_sub_resource_now(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_now_in_unix(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * try_resource_sub_resource_now_in_unix(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * resource_sub_resource_random(LuaCEmbedTable  *self,LuaCEmbed *args);

LuaCEmbedResponse * try_resource_sub_resource_random(LuaCEmbedTable  *self,LuaCEmbed *args);
