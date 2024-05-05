
---@class Bytes 
---@field size number
---@field get_byte_at_index fun(index:number):number


---@class DtwResource
---@field sub_resource fun(str:string) :DtwResource 
---@field __index fun(str:string) :DtwResource 
---@field get_value fun():string | number | boolean | nil | Bytes
---@field set_value fun(value:string | number | boolean | Bytes ) 
---@field commit fun()  apply the modifications
---@field lock fun() lock the resource from other process 
---@field unlock fun()
---@field unload fun() unload the content 


---@class DtwModule
---@field copy_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field copy_any_merging   fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_merging fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field remove_any fun(src:string):boolean returns true if the operation were ok otherwise false
---@field base64_encode_file fun(src:string):string transform file into base64 
---@field base64_encode fun(value:string | number | boolean | Bytes):string transform content into base64
---@field base64_decode fun(value:string): string | Bytes retransform base64 into normal value 
---@field list_files fun(src:string):string[] 
---@field list_dirs fun(src:string):string[] 
---@field list_all fun(src:string):string[] 
---@field list_files_recursively fun(src:string):string[] 
---@field list_dirs_recursively fun(src:string):string[] 
---@field list_all_recursively fun(src:string):string[] 
---@field load_file fun(src:string):string | Bytes
---@field write_file fun(src:string,value:string | number | boolean | Bytes)
---@field is_byte fun(value:any):boolean returns if a value is a byte
---@field newResource fun(src:string):DtwResource
---@field generate_sha fun(value:string | number | boolean | Bytes):string 
---@field generate_sha_from_file fun(src:string):string 

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
