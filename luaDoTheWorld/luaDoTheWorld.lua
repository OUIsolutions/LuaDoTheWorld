
---@class Bytes 


---@class DtwResource
---@field sub_resource fun(str:string) :DtwResource 
---@field get_value fun():string | number | boolean | nil | Bytes
---@field set_value fun(value:string | number | boolean | Bytes ) 

---@class DtwModule
---@field copy_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field copy_any_merging   fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_merging fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field remove_any fun(src:string):boolean returns true if the operation were ok otherwise false
---@field list_files fun(src:string):string[] 
---@field list_dirs fun(src:string):string[] 
---@field list_all fun(src:string):string[] 
---@field list_files_recursively fun(src:string):string[] 
---@field list_dirs_recursively fun(src:string):string[] 
---@field list_all_recursively fun(src:string):string[] 
---@field load_file fun(src:string) string | Bytes
---@field write_file fun(src:string,value:string | number | boolean | Bytes)
---@field newResource fun(src:string):DtwResource


local info = debug.getinfo(1, "S")
local path = info.source:match("@(.*/)") or ""




local lib_path = ''

if os.getenv("HOME") then
    lib_path = path.."luaDoTheWorld_clib.so"
else
    perror("undefined os") 
end 

local load_lua = package.loadlib(lib_path, "load_lua")

---@type DtwModule
local lib = load_lua()

return lib
