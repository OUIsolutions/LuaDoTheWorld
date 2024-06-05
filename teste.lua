


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local listage,size = dtw.list_files_recursively("banco")

for i=1,size do
	print(listage[i])
end