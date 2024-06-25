local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.newTransaction()

transaction.write("tests/target/a.txt","content of a")
transaction.remove_any("tests/target/test_dir")
transaction.copy_any("tests/target/a","tests/target/b")

local mapped,size = transaction.map(function (action)
    return {
      transaction_type=action.get_type(),
      source=action.get_source(),
      dest=action.get_dest(),
      content=action.get_content()
    }
end)

for i=1,size do
    local current = mapped[i]
	print("type",current.transaction_type)
	print("source",current.source)
	print("dest",current.dest)
	print("content",current.content)
end

