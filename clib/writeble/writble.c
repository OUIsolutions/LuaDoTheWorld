

Writeble  create_writeble(LuaCEmbed *args,int index){
    Writeble self = {0};
    long total_args = lua.args.size(args);
    if(total_args == 0){
        self.error = lua.response.send_error(ARGUMENT_NOT_PROVIDED);
        return self;
    }

    int type_to_write = lua.args.get_type(args,index);

    if(type_to_write == lua.types.STRING){

        self.content = (unsigned char*)lua.args.get_str(args,index);
        self.size = (long)strlen((char*)self.content);
    }

    else if(type_to_write == lua.types.NUMBER){
        self.clear_content = true;
        double content = lua.args.get_double(args,1);
        double rest = content - (double)(long ) content;
        if(rest == 0){
            char formatted[20] = {0};
            sprintf(formatted,"%ld",(long)content);
            self.content = (unsigned char*)strdup(formatted);
            self.size = (long)strlen(formatted);
        }
        else{
            char formatted[20] = {0};
            sprintf(formatted,"%lf",content);
            self.content = (unsigned char*)strdup(formatted);
            self.size = (long)strlen(formatted);
        }

    }
    else if(type_to_write == lua.types.BOOL){
        bool content  = lua.args.get_bool(args,1);
        const char *converted = content ? "true":"false";
        self.content = (unsigned char*)converted;
        self.size = (long)strlen(converted);
    }

    else if(type_to_write == lua.types.TABLE){
        LuaCEmbedTable * bytes = lua.args.get_table(args,1);
        LuaCEmbedResponse  *possible_error = ensure_table_type(bytes,BYTE_TYPE,BYTE_STRING);
        if(possible_error){
            self.error = possible_error;
            return self;
        }

        self.size = lua.tables.get_long_prop(bytes,SIZE);
        self.content =  (unsigned  char *)lua.tables.get_long_prop(bytes,CONTENT_POINTER);

    }
    else{
        char *error = private_LuaCembed_format(NOT_WRITEBLE_ELEMENT,lua.convert_arg_code(type_to_write));
        self.error = lua.response.send_error(error);
        free(error);
        return self;
    }
    return self;
}
void Writeble_free(Writeble *self){
    if(self->clear_content){
        free(self->content);
    }
}