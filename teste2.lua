
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.new_transaction()
transaction.write("a.txt","aaaaaaa")
transaction.write("b.txt","aaaaa")

local v = transaction[1]
print(v)