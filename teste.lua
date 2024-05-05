


local dtw = require("luaDoTheWorld/luaDoTheWorld")
local image = dtw.load_file("nada.jpg")
local encoded = dtw.base64_encode(image)
print(encoded)