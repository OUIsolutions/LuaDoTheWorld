local dtw = require("luaDoTheWorld/luaDoTheWorld")


local files, size = dtw.list_files_recursively("src", true)

for i = 1, size do
    local current = files[i]
    local path = dtw.newPath(current)
    local name = path.get_name()
    if name == "declaration.h" or name == "definition.h" then
        dtw.remove_any(current)
    end
    local dir = path.get_dir()
    local extension = path.get_extension()
    if dir == "src/constants/" then
        value_to_add = "consts." .. name
        path.set_name(value_to_add)
        dtw.move_any_overwriting(current, path.get_full_path())
    elseif extension == "c" then
        value_to_add = "fdefine." .. name
        path.set_name(value_to_add)
        dtw.move_any_overwriting(current, path.get_full_path())
    elseif extension == "h" then
        value_to_add = "fdeclare." .. name
        path.set_name(value_to_add)
        dtw.move_any_overwriting(current, path.get_full_path())
    end
end
