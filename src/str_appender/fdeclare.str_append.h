//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.type.h"
//silver_chain_scope_end



privateLuaDtwStringAppender *newprivateLuaDtwStringAppender();
void privateLuaDtwStringAppender_append(privateLuaDtwStringAppender *self, const char *str, long str_length);

void privateLuaDtwStringAppender_free(privateLuaDtwStringAppender *self);