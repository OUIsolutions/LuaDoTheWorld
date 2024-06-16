
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local hasher = dtw.newHasher()
hasher.digest_file("tests/target/blob.png")
hasher.digest("what ever you want")
hasher.digest_folder_by_content("tests/target/test_dir")
--will print the acumulated haher
print(hasher.get_value())