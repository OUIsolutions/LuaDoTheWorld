


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("/home/mateus/Documentos/OUI/production/lualibs/LuaDoTheWorld")
path.set_name("teste.txt")
local elements,size = path.unpack()

for i=1,size do
	print(elements[i])
end