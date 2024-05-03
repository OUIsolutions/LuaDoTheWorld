dtw = require("luaDoTheWorld/luaDoTheWorld")

local hasher = dtw.new_hasher()

hasher.digest_folder_by_content("clib")

print(tostring(hasher))