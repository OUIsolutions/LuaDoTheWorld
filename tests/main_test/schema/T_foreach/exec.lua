local dtw = require("luaDoTheWorld/luaDoTheWorld")

local function  create_database()
    local database = dtw.newResource("tests/target/database")
    local root_schema = database.newDatabaseSchema()
    local users  =root_schema.sub_schema("users")
    users.add_primary_keys({"name","email"})
    return database;
end

---@param database DtwResource
---@param name string
---@param email string
local function create_user(database,name,email,password)
    local users = database.sub_resource("users")
    local user = users.schema_new_insertion()
    user.set_value_in_sub_resource("name",name)
    user.set_value_in_sub_resource("email",email)
    local password_sha = dtw.generate_sha(password)
    user.set_value_in_sub_resource("password",password_sha)
    return user;
end


local database = create_database();
create_user(database,"user1","user1@gmail.com","123")
create_user(database,"user2","user2@gmail.com","123")

local users = database.sub_resource("users")
users.schema_each(function (current_user)
		print("name",current_user.get_value_from_sub_resource("name"))
    	print("email",current_user.get_value_from_sub_resource("email"))
    	print("password",current_user.get_value_from_sub_resource("password"))
end)
