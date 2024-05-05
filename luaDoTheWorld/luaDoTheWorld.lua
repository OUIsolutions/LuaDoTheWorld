
---@class Bytes 


---@class DtwResource
---@field sub_resource fun(str:string) :DtwResource
---@field get_value string | number | boolean | nil
---@field set_value fun(value:string | number | boolean | Bytes )


---@class DtwModule
---@field list_files fun(src:string):string[] list the files of dir
---@field list_dirs fun(src:string):string[] list the dirs of dirs
---@field list_all fun(src:string):string[] list all element of dir
---@field list_files_recursively fun(src:string):string[] list the files of dir recursively
---@field list_dirs_recursively fun(src:string):string[] list the dirs of dirs recursively
---@field list_all_recursively fun(src:string):string[] list all element of dir
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
