local dtw = require("luaDoTheWorld/luaDoTheWorld")


local files, size = dtw.list_files_recursively("src")

for i = 1, size do
    local current = files[i]
    local path = dtw.newPath(current)
    local name = path.get_name()
    if name == "declaration.h" or name == "definition.h" then
        dtw.remove_any(current)
    end
    local dir = path.get_dir()
    if dir == "constants/" then

    end
end
