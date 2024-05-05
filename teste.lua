local dtw = require("luaDoTheWorld/luaDoTheWorld")


local listage = dtw.list_all_recursively("clib")

for i,v in ipairs(listage) do 
    print(v)
end 
print("pegou depois")