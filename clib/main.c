
#include "dependecies.h"
#include "namespaces.h"
#include "declaration.h"
#include "definition.h"

int luaopen_doTheWorld(lua_State *state){
    lua = newLuaCEmbedNamespace();
    dtw = newDtwNamespace();
    bool set_functions_as_public  = false;
    LuaCEmbed * l  = lua.newLuaLib(state,set_functions_as_public);

    return lua.perform(l);

}