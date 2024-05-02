local function get_current_dir()
    local info = debug.getinfo(1, "S")
    local path = info.source:match("@(.*/)") or ""
    return path
end

local current_dir = get_current_dir()
local lib_path = ''
if os.getenv("HOME") then
    lib_path = current_dir.."luaDoTheWorld_clib.so"
end 

local lib = package.loadlib(lib_path, "luaopen_luaDoTheWorld_clib")()
return lib