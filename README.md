

Lua DoTheWorld its a Lua Lib to manipulate IO in all possible ways, providing 
from basic functions like, read/write/move/copy to listage and listage recurisively
to highly abstracted functions like transactions, hashing, seting primary keys, etc..

LuaDoTheWorld it's a wrapper of the original doTHeWorld lib that can be found in these repo

[DoTheWorld Link](https://github.com/OUIsolutions/DoTheWorld)



# Basics

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

local result = tree.map(function (element)

	return {path=element.path.get_full_path(),content=element.get_value()}

end)

local size = tree.get_size()
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