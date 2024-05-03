dtw = require("luaDoTheWorld/luaDoTheWorld")

local hasher = dtw.new_hasher()

hasher.digest("aaaa")
hasher.digest(10)
print(tostring(hasher))