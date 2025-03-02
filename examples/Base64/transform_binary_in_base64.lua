
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local image = dtw.load_file("tests/target/blob.png")
local inb64 = dtw.base64_encode(image)
print(inb64)
