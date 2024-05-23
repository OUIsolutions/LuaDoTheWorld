
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local banco = dtw.newResource("banco")
local schema = banco.newSchema()
local users_schema =schema.sub_schema("users")
users_schema.add_primary_keys({"name","email"})


local users = banco.sub_resource("users")
users.each_schema(function (value)
    print(value)
end)