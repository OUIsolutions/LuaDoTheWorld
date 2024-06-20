local dtw = require("luaDoTheWorld/luaDoTheWorld")


local ok,transaction_or_error = pcall(dtw.new_transaction_from_file,"tests/target/xxx.json")

if ok == false then
	print(transaction_or_error)
end