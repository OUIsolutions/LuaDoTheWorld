
#include "dependecies.h"
#include "namespaces.h"
#include "declaration.h"
#include "definition.h"

int luaopen_luaDoTheWorld_luaDoTheWorld_clib(lua_State *state){
    lua = newLuaCEmbedNamespace();
    dtw = newDtwNamespace();
    bool set_functions_as_public  = false;
    LuaCEmbed * l  = lua.newLuaLib(state,set_functions_as_public);
    lua.add_callback(l,LOAD_FILE,load_file);
    lua.add_callback(l,WRITE_FILE,write_file);
    return lua.perform(l);
}