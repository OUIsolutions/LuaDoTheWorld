local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.new_transaction_from_file("tests/target/xxx.json")
transaction.each(function (action)
	local dest = action.get_dest()
	local type = action.get_type()
	local to = action.get_source()
	local content = action.get_content()
	print("===================================")
	print("dest",dest)
	print("to",to)
	print("type",type)
	print("content",content)

end)