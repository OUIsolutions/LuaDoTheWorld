

local info = debug.getinfo(1, "S")
local path = info.source:match("@(.*/)") or ""

require(path.."types")


local lib_path = ''

if os.getenv("HOME") then
    lib_path = path.."luaDoTheWorld_clib.so"
else
    perror("undefined os") 
end 

local load_lua = package.loadlib(lib_path, "load_lua")

local lib = load_lua()
return lib
