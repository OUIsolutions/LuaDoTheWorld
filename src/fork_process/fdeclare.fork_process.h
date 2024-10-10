#ifdef  __linux__

//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.macros.h"
//silver_chain_scope_end

LuaCEmbedResponse * is_fork_alive(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * fork_delete(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * fork_wait(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * kill_process(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse * create_fork_process(LuaCEmbed *args);
#endif
