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
---@param age number
local function create_user(database,name,email,age,password)
    local users = database.sub_resource("users")
    local user = users.schema_new_insertion()
    user.set_value_in_sub_resource("name",name)
    user.set_value_in_sub_resource("email",email)
    user.set_value_in_sub_resource("age",age)
    local password_sha = dtw.generate_sha(password)
    user.set_value_in_sub_resource("password",password_sha)
    return user;
end


local database = create_database();
create_user(database,"user1","user1@gmail.com",20,"123")
create_user(database,"user2","user2@gmail.com",40,"123")
create_user(database,"user2","user3@gmail.com",50,"123")

local users = database.sub_resource("users")
local users_higher_than_30,size = users.schema_filter(function (current_user)

		if current_user.get_value_from_sub_resource("age") > 30 then
			return true
		end
end)

for i=1,size do
        local current_user = users_higher_than_30[i]
		print("name",current_user.get_value_from_sub_resource("name"))
    	print("email",current_user.get_value_from_sub_resource("email"))
    	print("age",current_user.get_value_from_sub_resource("age"))
    	print("password",current_user.get_value_from_sub_resource("password"))
end

database.commit()