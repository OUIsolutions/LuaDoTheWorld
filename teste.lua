local dtw = require("luaDoTheWorld/luaDoTheWorld")


local files, size = dtw.list_files_recursively("src")

for i = 1, size do
    print(files[i])
end
