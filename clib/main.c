
#include "dependecies.h"
#include "namespaces.h"
#include "declaration.h"
#include "definition.h"


void start_lua_props(LuaCEmbed *l){
    lua.add_callback(l,LOAD_FILE,load_file);
    lua.add_callback(l,WRITE_FILE,write_file);
    lua.add_callback(l,COPY_ANY_OVERWRITING,copy_any_overwriting);
    lua.add_callback(l,COPY_ANY_MERGING,copy_any_merging);
    lua.add_callback(l,MOVE_ANY_OVERWRITING,move_any_overwriting);
    lua.add_callback(l,MOVE_ANY_MERGING,move_any_merging);
    lua.add_callback(l,REMOVE_ANY,remove_any);

    lua.add_callback(l,LIST_FILES,list_files);
    lua.add_callback(l,LIST_FILES_RECURSIVELY,list_files_recursively);
    lua.add_callback(l,LIST_DIRS,list_dirs_recursively);
    lua.add_callback(l,LIST_DIRS_RECURSIVELY,list_dirs_recursively);
    lua.add_callback(l,LIST_ALL,list_all);
    lua.add_callback(l,LIST_ALL_RECURSIVELY,list_all_recursively);


}

int load_lua(lua_State *state){
    lua = newLuaCEmbedNamespace();
    dtw = newDtwNamespace();
    bool set_functions_as_public  = false;
    LuaCEmbed * l  = lua.newLuaLib(state,set_functions_as_public);
    start_lua_props(l);
    return lua.perform(l);
}