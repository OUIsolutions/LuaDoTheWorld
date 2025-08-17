//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.type.h"
//silver_chain_scope_end
#if defined(__linux__) || defined(__APPLE__)

LuaCEmbedResponse * is_fork_alive(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * fork_delete(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * fork_wait(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * kill_process(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * create_fork_process(LuaCEmbed *args);
#endif
