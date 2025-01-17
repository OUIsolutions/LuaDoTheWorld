

Lua DoTheWorld its a Lua Lib to manipulate IO in all possible ways, providing
from basic functions like, read/write/move/copy to listage and listage recurisively
to highly abstracted functions like transactions, hashing, seting primary keys, etc..

LuaDoTheWorld it's a wrapper of the original doTHeWorld lib that can be found in these repo

[Do The World](https://github.com/OUIsolutions/DoTheWorld)

## Installation
To install the lib, just download the lib [Lib Download](https://github.com/OUIsolutions/LuaDoTheWorld/releases/download/v0.07/luaDoTheWorld.zip)
in the root of your project, and run with:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
```
#### Installation from Command
if you prefer to install with a command, just type:
```shell
curl -L -o luaDoTheWorld.zip https://github.com/OUIsolutions/LuaDoTheWorld/releases/download/v0.06/luaDoTheWorld.zip && unzip luaDoTheWorld.zip -d luaDoTheWorld && rm luaDoTheWorld.zip
```

#### Build from scratch
if you want to build from scracth , just clone these repo into your machine, and run:
it will prodice,the **luaDoTheWorld/luaDoTheWorld_clib.so** link lib
```shell
gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  src/one.c
```
#### Perform tests
if you want to perform the tests, just run the **build.out** executable



## Disclaimers
<h3 style="color: red">These lib only suport lua 5.4 > on linux</h3>
<h3 style="color: red">Dispite been convered by test, these lib its not production ready yet</h3>



## The Try Mechanic
Since you may want to run the lib into a enviroment that pcall its not availiable, thes lib provides
the try mechanic to all functions that can not be tested into a verify first aproach, each function
that has **try** before the function , will always return an bolean, followed by the value ,or the error
of the value.


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

~~~


## Basics

### Loading a file

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local a  = dtw.load_file("tests/target/a.txt")
print(a)

~~~


### Writing a file

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.write_file("tests/target/b.txt","text content")



~~~

### Copying anything overwiting content
the copy overwrite will copy overwriting whatever it's placed inside desteny


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.copy_any_overwriting("tests/target/test_dir","tests/target/a")
~~~

### Copying Anything Merging
these  copy will try to merge toe folder (if its a folder) with the dest


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.copy_any_merging("tests/target/test_dir","tests/target/a")
~~~

### Move AnyThing Overwriting
will move anything (folder/file) to the dest, removing the dest if exist


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.move_any_overwriting("tests/target/test_dir","tests/target/a")
~~~

### Move AnyThing Moerve
will move anything (folder/file) to the dest, merging with the content of the dest
if dest its a folder


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

dtw.move_any_merging("tests/target/test_dir","tests/target/a")
~~~

### Listage

#### List files

will list all files of the current dir, as optional second argument, you can pass if
its to concat the path withing the listage


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false
local files,size = dtw.list_files("tests/target/test_dir",concat_path)


for i=1,size do
	local current = files[i]
	print(current)
end
~~~

### List Dirs

will list all the dirs of the given dir


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false

local dirs,size = dtw.list_dirs("tests/target/test_dir",concat_path)


for i=1,size do
	local current = dirs[i]
	print(current)
end
~~~


### List All
Will list dirs and files of the given dir


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false
local elements,size = dtw.list_all("tests/target/test_dir",concat_path)

for i=1,size do
	local current = elements[i]
	print(current)
end
~~~

### List Files Recursively
Will list files recursively of the given dir


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false

local files,size = dtw.list_files_recursively("tests/target/test_dir",concat_path)

for i=1,size do
	local current = files[i]
	print(current)
end
~~~

### List Dirs Recursively
Will list all the dirs of the given dir recursively


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false

local dirs,size = dtw.list_dirs_recursively("tests/target/test_dir",concat_path)



for i=1,size do
	local current = dirs[i]
	print(current)
end
~~~

### List All Recursively
Will list anything given dir recursively


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")


local concat_path  = false

local elements,size = dtw.list_all_recursively("tests/target/test_dir",concat_path)

for i=1,size do
	local current = elements[i]
	print(current)
end
~~~
### Base64
you can encode and decode files to base64 easly with luaDoTheWorld

#### Enconding a binary

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local inb64 = dtw.base64_encode_file("tests/target/blob.png")
print(inb64)

~~~

#### Encoding a File


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local inb64 = dtw.base64_encode_file("tests/target/blob.png")
local image = dtw.base64_decode(inb64)
dtw.write_file("tests/target/blob2.png",image)
~~~

#### Retransform b64 to binary

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local image = dtw.load_file("tests/target/blob.png")
local inb64 = dtw.base64_encode(image)
print(inb64)

~~~

### Getting Entity Last Modification
if you want to get the  folder/file last modification, its also possible

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local last = dtw.get_entity_last_modification("tests/target/blob.png")
print(last)
~~~

### Getting Entity Last Modification in Unix
you also can generate it in unix


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local last_in_unix = dtw.get_entity_last_modification_in_unix("tests/target/blob.png")
print(last_in_unix)
~~~

### Hashing
You can generate assignature of anything you want  with all the hash functions

#### Generating Sha from string
Will generate a sha256 assignature of a string

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha("what ever you want")
print(sha)
~~~

#### Generating Sha from file
Will generate a sha256 assignature of a file

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_file("tests/target/blob.png")
print(sha)
~~~

#### Generating Sha from folder by content
Will generate a sha256 assignature of a folder based on content

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_folder_by_content("tests/target/test_dir")
print(sha)
~~~


#### Generating Sha from folder by last modification
Will generate a sha256 assignature of a folder based on last modification

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_folder_by_last_modification("tests/target/test_dir")
print(sha)
~~~

### Hasher
if you need to combine a lot of different entries, you can use the DtwHasher object


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local hasher = dtw.newHasher()
hasher.digest_file("tests/target/blob.png")
hasher.digest("what ever you want")
hasher.digest_folder_by_content("tests/target/test_dir")
--will print the acumulated haher
print(hasher.get_value())
~~~

### Path
Path its a algo class to handle path logics

#### Basic path extraction

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
local name = path.get_name()
local dir = path.get_dir()
local extension = path.get_extension()
print("name",name)
print("dir",dir)
print("extension",extension)
~~~

#### Extracting Sub dirs
You also can extract sub dirs, by passing start and end keyworks (-1 its the last, -2 the second last)


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
local sub_dirs = path.get_sub_dirs_from_index(1,-1)
print(sub_dirs)
~~~


#### Basic Path Insertions

#### Set Dir

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.set_dir("test")
print(path.get_full_path())
~~~

#### Set Name

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.set_name("d.txt")
print(path.get_full_path())
~~~

#### Set Extension

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.set_extension("py")
print(path.get_full_path())
~~~


#### Inserting dirs at after point

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.insert_dir_after("a","inserted_dir")
print(path.get_full_path())
~~~

#### Inserting dirs at before point

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.insert_dir_before("a","inserted_dir")
print(path.get_full_path())
~~~

#### Inserting dirs at index

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.insert_dir_at_index(1,"inserted_dir")
print(path.get_full_path())
~~~

#### Replacing Dirs

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local path = dtw.newPath("a/b/c.txt")
path.replace_dirs("a","inserted_dir")
print(path.get_full_path())
~~~



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


### Trees and Tree Parts

Trees and Tree parts are a way to manage files in a one dimension list

#### Creating a Tree
in these example, we create a tree

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree()
local a = tree.newTreePart_empty("tests/target/Tree/a.txt")
a.set_value("content of a")
a.hardware_write()
local b = tree.newTreePart_empty("tests/target/Tree/b.txt")
a.set_value("content of b")
a.hardware_write()

tree.commit()


~~~


### Modifying a Tree
Here we set all txt extension to py extension of a loaded tree

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

tree.each(function (element)

	if element.path.get_extension()== "txt" then
		element.path.set_extension("py")
	end
	element.hardware_modify()
end)

tree.commit()
~~~

#### Map Tree
You also can map trees , to create custom objects list derived from tree parts


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local result,size = tree.map(function (element)

	return {path=element.path.get_full_path(),content=element.get_value()}

end)
for i=1,size do
    local current  = result[i]
    print("========================")
    print("path",current.path)
    print("content",current.content)

end

~~~

#### Count Tree
or you can count tree parts that fits conditions

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local size = tree.count(function (element)

	if element.path.get_extension() == "py" then
		return true
	end
end)


print(size)
~~~
`
`### Hardwar Operators
These tree actions type on tree behave different on each other
#### Hardware Write
Hardware Write will make the changes ,ignoring previews existence
for example ,if a file its "a.txt"  and you set the path to "b.txt" it will
create a new file "b.txt" ignoring a.txt, but if you set the content of a.txt without
modifying the path, it will overwrite the "a.txt"


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
        return true;
	end
end)
target.path.set_name("new_name.txt")
target.hardware_write()

tree.commit()


~~~

#### Hardware Modify
Hardware Modify will consider previews path, and in the same example, if you change the path
from "a.txt" to "b.txt" it will rename the file

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
        return true;
	end
end)
target.path.set_name("new_name.txt")
target.hardware_modify()

tree.commit()


~~~

#### Hardware Remove
These directive will remove the given tree part that you typed

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
        return true;
	end
end)

target.path.set_name("new_name.txt")
target.hardware_remove()

tree.commit()


~~~

### DtwFork
with DtwFork you can fork process easily
~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
	print("executed inside")
end)
local one_second = 1000
fork.wait(one_second)

print("executed in main prrocess")

~~~

you also can interrupt the code forcing kill

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local fork = dtw.newFork(function ()
    while true do
	    print("executed inside")
    end
end)

local half_second = 500

fork.wait(half_second)
if fork.is_alive() then
	fork.kill()
end

print(" executed in main prrocess")
~~~

### Locker
with Locker you can lock files ,and manage concurrency betwen process,
Note that locker does not prevent concurrency on multithread, only in multiprocess
that use the same locker system (doTheWorld in C) or (luaDoTheWorld)


~~~lua




local dtw = require("luaDoTheWorld/luaDoTheWorld")

local locker = dtw.newLocker()
locker.lock("a.txt")
locker.unlock("a.txt");

~~~

In these example, we are creeating 30 forks ,and writing a file with the given number

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local all_forks = {}
local total_forks = 30

dtw.remove_any("a.txt")

for i=1,  total_forks do
    local fork = dtw.newFork(function ()
         local locker = dtw.newLocker()
         locker.lock("a.txt")
         local old = dtw.load_file("a.txt")

         if old == nil then
         	old = ""
         end

         old = old..i.."\n"
         dtw.write_file("a.txt",old)
         locker.unlock("a.txt")
    end)
    all_forks[i] = fork
end

--- waiting all childs
for i=1,total_forks do
    local current= all_forks[i]
    current.wait(-1)
end

~~~