
### Base64
you can encode and decode files to base64 easly with luaDoTheWorld

#### Enconding a binary

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local inb64 = dtw.base64_encode_file("tests/target/blob.png")
print(inb64)

~~~

#### Encoding a File


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local inb64 = dtw.base64_encode_file("tests/target/blob.png")
local image = dtw.base64_decode(inb64)
dtw.write_file("tests/target/blob2.png",image)
~~~

#### Retransform b64 to binary

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local image = dtw.load_file("tests/target/blob.png")
local inb64 = dtw.base64_encode(image)
print(inb64)

~~~
