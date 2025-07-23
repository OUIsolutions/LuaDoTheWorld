//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end


typedef struct privateLuaDtwStringAppender {
    char *buffer;
    long buffer_size;
    long length;
} privateLuaDtwStringAppender;

privateLuaDtwStringAppender *newprivateLuaDtwStringAppender(){
    privateLuaDtwStringAppender *self = (privateLuaDtwStringAppender *)malloc(sizeof(privateLuaDtwStringAppender));
    self->buffer = (char*)malloc(0);
    self->buffer_size = 0;
    self->length = 0;
    return self;
}
void privateLuaDtwStringAppender_append(privateLuaDtwStringAppender *self, const char *str, long str_length) {
    if (self->length + str_length >= self->buffer_size) {
        self->buffer_size = (self->length + str_length) * 2; // Double the size
        self->buffer = (char*)realloc(self->buffer, self->buffer_size);
    }
    memcpy(self->buffer + self->length, str, str_length);
    self->length += str_length;
}
void privateLuaDtwStringAppender_free(privateLuaDtwStringAppender *self) {
    if (self) {
        free(self->buffer);
        free(self);
    }
}