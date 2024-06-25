local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.newTransaction()

transaction.write("tests/target/a.txt","content of a")
transaction.remove_any("tests/target/test_dir")
transaction.copy_any("tests/target/a","tests/target/b")

local actions,size = transaction.list()
for i=1,size do
	local action = actions[i]
	print("type",action.get_type())
	print("source",action.get_source())
	print("dest",action.get_dest())
	print("content",action.get_content())
end

