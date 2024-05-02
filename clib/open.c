
#include "dependencies/LuaCEmbed.h"
#include "dependencies/doTheWorld.h"


LuaCEmbedNamespace  lua;
DtwNamespace dtw;

int luaopen_doTheWorld(lua_State *state){
    lua = newLuaCEmbedNamespace();
    dtw = newDtwNamespace();
    bool set_functions_as_public  = false;
    LuaCEmbed * l  = lua.newLuaLib(state,set_functions_as_public);



}