
### Resources
Resources it's a way to manipulate files and folders, as dictionarys, they are usefull for
larger storage models

#### Basic Resource in Lua

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local b = a.sub_resource("b.txt")
b.set_value("content of b1")
a.commit()

~~~

Resources can be files or folders, that are automaticly determined based on the code behavior
for example, if you use the function "get_value" the lib understand that its a file , if you type
sub resource, it understand that its a folder

#### Getting a value from a file
in these example we are getting a value from a faile


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local b = a.sub_resource("b.txt")
print(b.get_value())
a.commit()

~~~

#### Getting  a value from a sub resource
In these example we are getting a value from a sub resource directaly


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")

print(a.get_value_from_sub_resource("b.txt"))
~~~

#### Setting Values in Sub Resource


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
a.set_value_in_sub_resource("b.txt","content of b")
a.commit()

~~~

#### Destroying a sub resource
you also can destroy a resource


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local b = a.sub_resource("b.txt")
b.destroy()

a.commit()

~~~


#### Listage
there is a lot of ways to list into  files in lua,based on your style of coding

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local elements,size = a.list()

for i=1,size do
    local value = elements[i]
	print("path",value.get_path_string())
	print("type",value.get_type())
end



~~~

#### Each
if you prefer  a more functional way ,you can use the each method for basic iteration


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
a.each(function (value)
	print("path",value.get_path_string())
	print("type",value.get_type())
end)

~~~

#### Map
you also can map the resources retriving a generated struct


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local elements,size  = a.map(function(value)
	local result = {}
	result.path = value.get_path_string()
    result.value = value.get_value()
    result.type = value.get_type()
    return result;
end)
for i=1,size do
	local current = elements[i]
	print("path",current.path)
	print("value",current.value)
	print("type",current.type)
end
~~~

#### Find
its possible to find elements based on functions to


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local element  = a.find(function(value)
	local path = dtw.newPath(value.get_path_string())
    if path.get_name() == "a.txt" then
    	return true;
    end
end)

print(element.get_value())
~~~

#### Filter
and you can filter elements, in these example we are filtering based on file exist


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/test_dir")
local files,size  = a.filter(function(value)
	if value.get_value() then
		return true
	end
end)


for i=1,size do
	local file = files[i]
	print(file.get_value())
end
~~~

#### Custom sub Resources
With Custom sub resources , you can generate customizible elements to your resources
making elements based onyour necessity

#### Sub Resource Now

will create a sub resource with the name of the current time

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local now = a.sub_resource_now(".txt")
now.set_value("content generated")
a.commit()

~~~

#### Sub Resource Now in Unix

Will create a resource with the current unix time

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local now = a.sub_resource_now_in_unix(".txt")
now.set_value("content generated")
a.commit()

~~~

#### Sub Resource Random
Will create a resource with a random name


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local now = a.sub_resource_random(".txt")
now.set_value("content generated")
a.commit()

~~~

#### Sub Resource Next
will creeate a resource with the given size of mothers folder


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a = dtw.newResource("tests/target/a")
local next = a.sub_resource_next(".txt")
next.set_value("content generated")
a.commit()

~~~


### Schemas
Schemas its a way to emulate relational behavior inside resource system
its super usefull for larger storage models, int contemplates, insertions and primary keys
(joins  maybe will be avaliable in the future)

#### Basic Schema Insertion


~~~lua
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
local correct,user_or_error  = pcall(create_user,database,"user1","user1@gmail.com","123")
if correct == false then
	local error = user_or_error
	print(error)
else
	print("user created")
end

database.commit()

~~~

#### Finding By Primary key
you also can find elements based on their primary key


~~~lua
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
if first_user ~= nil then
    print("name",first_user.get_value_from_sub_resource("name"))
    print("email",first_user.get_value_from_sub_resource("email"))
    print("password",first_user.get_value_from_sub_resource("password"))
else
    print("user not found")
end

database.commit()

~~~

#### Destroying
the schema destruction grants the system integridy, so all the entity and its keys, will be destroyed


~~~lua
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
first_user.destroy()
print("user destroyed")
database.commit()
~~~

#### Schema Listage
You can also list elements of the schema easly

~~~lua
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
local elements,size= users.schema_list()
for i=1,size do
	local current_user = elements[i]
	print("name",current_user.get_value_from_sub_resource("name"))
	print("email",current_user.get_value_from_sub_resource("email"))
	print("password",current_user.get_value_from_sub_resource("password"))
end

database.commit()

~~~

#### Schema Each
if you prefer an functional aproact , each its also available


~~~lua
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
database.commit()
~~~

#### Schema Map
if you need to construct a struct of your schema ( to return in web apis for example)map its also available

~~~lua
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
local users_mapped,size = users.schema_map(function (current_user)
		return {
		   name= current_user.get_value_from_sub_resource("name"),
		   email = current_user.get_value_from_sub_resource("email"),
		   password = current_user.get_value_from_sub_resource("password")
		}
end)

for i=1,size do
    local current_user = users_mapped[i]
	print("name",current_user.name)
	print("email",current_user.email)
	print("password",current_user.password)
end


database.commit()
~~~

#### Schema Filter
you also can aply filtrage in schemas


~~~lua
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
create_user(database,"user3","user3@gmail.com",50,"123")

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
~~~

