
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local inb64 = dtw.base64_encode_file("tests/target/blob.png")
print(inb64)
