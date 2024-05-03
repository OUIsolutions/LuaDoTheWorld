local dtw = require("luaDoTheWorld/luaDoTheWorld")

local hasher = dtw.new_hasher()

hasher.digest_folder_by_content("fff")

print(tostring(hasher))

