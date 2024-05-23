
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local resource = dtw.newResource("banco")
local schema = resource.newSchema()
local users_schema =schema.sub_schema("users")
users_schema.add_primary_keys({"name","email"})


local users = resource.sub_resource("users")
local mateus  =users.new_insertion()

mateus.set_value_in_sub_resource("name","mateus")
resource.commit()

