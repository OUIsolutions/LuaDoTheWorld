
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_file("tests/target/blob.png")
print(sha)