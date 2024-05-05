



---@class DtwModule
---@field list_files fun(src:string):string[]
---@field list_dirs fun(src:string):string[]
---@field list_all fun(src:string):string[]
---@field list_files_recursively fun(src:string):string[]
---@field list_dirs_recursively fun(src:string):string[]
---@field list_all_recursively fun(src:string):string[]



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
