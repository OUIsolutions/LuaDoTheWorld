//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



privateLuaDtwStringAppender *newprivateLuaDtwStringAppender(){
    privateLuaDtwStringAppender *self = (privateLuaDtwStringAppender *)malloc(sizeof(privateLuaDtwStringAppender));
    self->buffer = (char*)malloc(0);
    self->buffer_size = 0;
    self->length = 0;
    return self;
}
void privateLuaDtwStringAppender_append(privateLuaDtwStringAppender *self, const char *str) {
     long str_length = strlen(str);
    if (self->length + str_length >= self->buffer_size) {
        self->buffer_size = (self->length + str_length) * 2; // Double the size
        self->buffer = (char*)realloc(self->buffer, self->buffer_size);
    }
    memcpy(self->buffer + self->length, str, str_length);
    self->buffer[self->length + str_length] = '\0'; // Null-terminate the string
    self->length += str_length;
}
void privateLuaDtwStringAppender_append_fmt(privateLuaDtwStringAppender *self, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    // Get the formatted string length
    long str_length = vsnprintf(NULL, 0, fmt, args);
    if (self->length + str_length >= self->buffer_size) {
        self->buffer_size = (self->length + str_length) * 2; // Double the size
        self->buffer = (char*)realloc(self->buffer, self->buffer_size);
    }
    // Write the formatted string to the buffer
    vsnprintf(self->buffer + self->length, self->buffer_size - self->length, fmt, args);
    self->length += str_length;
    va_end(args);
}

 



void privateLuaDtwStringAppender_free(privateLuaDtwStringAppender *self) {
    if (self) {
        free(self->buffer);
        free(self);
    }
}