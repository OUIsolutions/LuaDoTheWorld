//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../src/imports/imports.type.h"
//silver_chain_scope_end



LuaCEmbedResponse  * load_file(LuaCEmbed *args);

LuaCEmbedResponse  * write_file(LuaCEmbed *args);

LuaCEmbedResponse  * copy_any_overwriting(LuaCEmbed *args);

LuaCEmbedResponse  * is_dir(LuaCEmbed *args);
LuaCEmbedResponse  * is_blob(LuaCEmbed *args);

LuaCEmbedResponse  * is_blob_file(LuaCEmbed *args);

LuaCEmbedResponse  * exist(LuaCEmbed *args);

LuaCEmbedResponse  * is_file(LuaCEmbed *args);



LuaCEmbedResponse  * copy_any_merging(LuaCEmbed *args);

LuaCEmbedResponse  * move_any_overwriting(LuaCEmbed *args);

LuaCEmbedResponse  * move_any_merging(LuaCEmbed *args);

LuaCEmbedResponse  * remove_any(LuaCEmbed *args);
