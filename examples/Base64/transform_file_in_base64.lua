
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local inb64 = dtw.base64_encode_file("tests/target/blob.png")
local image = dtw.base64_decode(inb64)
dtw.write_file("tests/target/blob2.png",image)