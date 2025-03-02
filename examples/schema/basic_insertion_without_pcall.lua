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
    local correct,error = user.try_set_value_in_sub_resource("name",name)
    if correct == false then
    	return false,error
    end

    correct,error = user.try_set_value_in_sub_resource("email",email)
    if correct == false then
        return false,error
    end


    local password_sha = dtw.generate_sha(password)
    user.set_value_in_sub_resource("password",password_sha)
    return true,user;
end



local database = create_database();
local correct,user_or_error  =create_user(database,"user1","user1@gmail.com","123")
if correct == false then
	local error = user_or_error
	print(error)
else
	print("user created")
end

database.commit()
