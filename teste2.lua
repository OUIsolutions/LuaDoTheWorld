
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local banco = dtw.newResource("banco")
local schema = banco.newSchema()
local users_schema =schema.sub_schema("users")
users_schema.add_primary_keys({"name","email"})



local users = banco.sub_resource("users")

--local r = users.schema_new_insertion()
--r.set_value_in_sub_resource("name","yasmin")
--banco.commit()


users.schema_each(function (value)
    print(value)
end)
