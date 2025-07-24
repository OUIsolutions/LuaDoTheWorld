//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.type.h"
//silver_chain_scope_end



privateLuaDtwStringAppender *newprivateLuaDtwStringAppender();
void privateLuaDtwStringAppender_append(privateLuaDtwStringAppender *self, const char *str);
void privateLuaDtwStringAppender_append_fmt(privateLuaDtwStringAppender *self, const char *fmt, ...);
void privateLuaDtwStringAppender_free(privateLuaDtwStringAppender *self);