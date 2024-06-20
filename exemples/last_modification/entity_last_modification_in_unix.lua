local dtw = require("luaDoTheWorld/luaDoTheWorld")

local last_in_unix = dtw.get_entity_last_modification_in_unix("tests/target/blob.png")
print(last_in_unix)