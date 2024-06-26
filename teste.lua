local dtw = require("luaDoTheWorld/luaDoTheWorld")

local content = dtw.load_file("teste.json")
local src2 = dtw.newTree_from_json_string("aa")
src2.each(function (v)
	print(v.path)
end)

