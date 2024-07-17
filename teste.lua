
local dtw = require("luaDoTheWorld/luaDoTheWorld")



local banco = dtw.newResource("banco")

local sla, size = banco.list()

print(size)
print(sla[1].get_path_string)
for i=1, size do

	print(sla[i].get_path_string())
end