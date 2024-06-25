local dtw = require("luaDoTheWorld/luaDoTheWorld")

local content = "{'aaa}"
local ok,transaction_or_error = dtw.try_new_transaction_from_string(content)
if ok == false then
	print(transaction_or_error)
end