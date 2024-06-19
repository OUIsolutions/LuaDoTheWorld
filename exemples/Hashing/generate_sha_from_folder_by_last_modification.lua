
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_folder_by_last_modification("tests/target/test_dir")
print(sha)