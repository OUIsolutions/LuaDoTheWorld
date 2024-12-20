local dtw    = require("luaDoTheWorld/luaDoTheWorld")

itens        = dtw.list_files_recursively("src", true)
local hasher = dtw.newHasher()

for i = 1, #itens do
    hasher.digest(dtw.load_file(itens[i]))
end
print(hasher)
