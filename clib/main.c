
#include "dependecies.h"
#include "namespaces.h"
#include "declaration.h"
#include "definition.h"


void start_lua_functions(LuaCEmbed *l){
    lua.add_callback(l,LOAD_FILE,load_file);
    lua.add_callback(l,WRITE_FILE,write_file);
}

int load_lua(lua_State *state){
    lua = newLuaCEmbedNamespace();
    dtw = newDtwNamespace();
    bool set_functions_as_public  = false;
    LuaCEmbed * l  = lua.newLuaLib(state,set_functions_as_public);
    start_lua_functions(l);
    return lua.perform(l);
}