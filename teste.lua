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

---@param database DtwResource
---@param email string
---@return DtwResource
local function find_by_email(database,email)
    local users = database.sub_resource("users")
    return users.get_resource_matching_primary_key("email",email)
end

local database = create_database();
create_user(database,"user1","user1@gmail.com","123")
create_user(database,"user2","user2@gmail.com","123")

local first_user = find_by_email(database,"user1@gmail.com")
local name = first_user.sub_resource("name")
print(name.get_value())

