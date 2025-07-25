
### Transaction
Transactions its a way to write actions in a atomic way, preventing crashing operations


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.newTransaction()

transaction.write("tests/target/a.txt","content of a")
transaction.remove_any("tests/target/test_dir")
transaction.copy_any("tests/target/a","tests/target/b")
transaction.commit()

~~~

#### Dumping Transaction to json
you also can store a transaction into a json, to load it in the future, or in a diferent
os

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.newTransaction()

transaction.write("tests/target/a.txt","content of a")
transaction.remove_any("tests/target/test_dir")
transaction.copy_any("tests/target/a","tests/target/b")
local transaction_json = transaction.dump_to_json_string()
print(transaction_json)
~~~


#### Loading a transactiion from json
these example loads a transaction from a json file



~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local transaction = dtw.new_transaction_from_file("tests/target/json_transaction.json")
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

~~~

