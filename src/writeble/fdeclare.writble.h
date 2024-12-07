
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.macros.h"
//silver_chain_scope_end


typedef struct{
    unsigned  char *content;
    bool clear_content;
    long size;
    bool is_binary;
    LuaCEmbedResponse  *error;
}Writeble;

Writeble  *create_writeble(LuaCEmbed *args,int index);

void Writeble_free(Writeble *self);
