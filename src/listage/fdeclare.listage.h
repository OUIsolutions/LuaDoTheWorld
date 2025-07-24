//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.type.h"
//silver_chain_scope_end


LuaCEmbedResponse  * aply_listage(LuaCEmbed *args,DtwStringArray* (*callback)(const char *folder,bool concat_path));


LuaCEmbedResponse  * list_files(LuaCEmbed *args);

LuaCEmbedResponse  * list_dirs(LuaCEmbed *args);

LuaCEmbedResponse  * list_all(LuaCEmbed *args);

LuaCEmbedResponse  * list_files_recursively(LuaCEmbed *args);

LuaCEmbedResponse  * list_dirs_recursively(LuaCEmbed *args);

LuaCEmbedResponse  * list_all_recursively(LuaCEmbed *args);
