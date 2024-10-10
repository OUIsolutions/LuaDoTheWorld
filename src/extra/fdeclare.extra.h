
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.macros.h"
//silver_chain_scope_end

bool get_table_props_or_default_bool(LuaCEmbedTable *table,const char *prop,bool default_value);


LuaCEmbedResponse * concat_path(LuaCEmbed *args);

LuaCEmbedResponse * starts_with(LuaCEmbed *args);

LuaCEmbedResponse * ends_with(LuaCEmbed *args);
