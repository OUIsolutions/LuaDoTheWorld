dtw = require("luaDoTheWorld/luaDoTheWorld")


local r = dtw.load_file("deer.jpg")
dtw.write_file("saida.jpg",r)

local sha  = dtw.generate_sha_from_file(10)
