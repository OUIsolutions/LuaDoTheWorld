
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.new_transaction()
transaction.write("teste.txt","aaaaaaaa")
transaction.write("teste2.txt","bbb")

local v = transaction.map(function (element )
	    return element.get_content() + "aaaaa"
end)
print(v[1])