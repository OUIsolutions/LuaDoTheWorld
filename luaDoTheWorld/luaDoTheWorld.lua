

local info = debug.getinfo(1, "S")
local path = info.source:match("@(.*/)") or ""

-- @class DtwModule
-- @field list_files integer
-- @field list_dirs integer


local lib_path = ''

if os.getenv("HOME") then
    lib_path = path.."luaDoTheWorld_clib.so"
else
    perror("undefined os") 
end 

local load_lua = package.loadlib(lib_path, "load_lua")
--@type DtwModule
local lib = load_lua()

return lib
