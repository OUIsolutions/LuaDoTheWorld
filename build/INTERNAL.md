

Lua DoTheWorld its a Lua Lib to manipulate IO in all possible ways, providing 
from basic functions like, read/write/move/copy to listage and listage recurisively
to highly abstracted functions like transactions, hashing, seting primary keys, etc..

LuaDoTheWorld it's a wrapper of the original doTHeWorld lib that can be found in these repo

## Installation 
To install the lib, just download the lib [Lib Download](https://github.com/OUIsolutions/LuaDoTheWorld/releases/download/v0.01/luaDoTheWorld.zip)
in the root of your project, and run with:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
```
#### Installation from Command 
if you prefer to install with a command, just type:
```shell
curl -L -o luaDoTheWorld.zip https://github.com/OUIsolutions/LuaDoTheWorld/releases/download/v0.01/luaDoTheWorld.zip && unzip luaDoTheWorld.zip -d luaDoTheWorld && rm luaDoTheWorld.zip
```
#### Build from scratch
if you want to build from scracth , just clone these repo into your machine, and run:
it will prodice,the **luaDoTheWorld/luaDoTheWorld_clib.so** link lib
```shell
gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  src/one.c
```
#### Perform tests
if you want to perform the tests, just run the **build.out** executable


[DoTheWorld Link](https://github.com/OUIsolutions/DoTheWorld)


## Disclaimers
<h3 style="color: red">These lib only suport lua 5.4 > on linux</h3>
<h3 style="color: red">Dispite been convered by test, these lib its not production ready yet</h3>



## The Try Mechanic 
Since you may want to run the lib into a enviroment that pcall its not availiable, thes lib provides 
the try mechanic to all functions that can not be tested into a verify first aproach, each function
that has **try** before the function , will always return an bolean, followed by the value ,or the error
of the value.

codeof:exemples/schema/basic_insertion_without_pcall.lua


## Basics

### Loading a file
codeof:exemples/IO/load_file.lua


### Writing a file 
codeof:exemples/IO/write_file.lua

### Copying anything overwiting content
the copy overwrite will copy overwriting whatever it's placed inside desteny

codeof:exemples/IO/copy_any_overwriting.lua

### Copying Anything Merging
these  copy will try to merge toe folder (if its a folder) with the dest

codeof:exemples/IO/copy_any_merging.lua

### Move AnyThing Overwriting 
will move anything (folder/file) to the dest, removing the dest if exist

codeof:exemples/IO/move_any_overwriting.lua

### Move AnyThing Moerve
will move anything (folder/file) to the dest, merging with the content of the dest
if dest its a folder

codeof:exemples/IO/move_any_merging.lua

### Listage 

#### List files 

will list all files of the current dir, as optional second argument, you can pass if 
its to concat the path withing the listage

codeof:exemples/listage/list_files.lua

### List Dirs 

will list all the dirs of the given dir 

codeof:exemples/listage/list_dirs.lua


### List All 
Will list dirs and files of the given dir 

codeof:exemples/listage/list_all.lua

### List Files Recursively
Will list files recursively of the given dir

codeof:exemples/listage/list_files_recursively.lua

### List Dirs Recursively
Will list all the dirs of the given dir recursively

codeof:exemples/listage/list_dirs_recursively.lua

### List All Recursively
Will list anything given dir recursively

codeof:exemples/listage/list_all_recursively.lua
### Base64
you can encode and decode files to base64 easly with luaDoTheWorld

#### Enconding a binary 
codeof:exemples/Base64/transaform_b64_string_in_binary.lua

#### Encoding a File 

codeof:exemples/Base64/transform_file_in_base64.lua

#### Retransform b64 to binary 
codeof:exemples/Base64/transform_binary_in_base64.lua

### Getting Entity Last Modification
if you want to get the  folder/file last modification, its also possible
codeof:exemples/last_modification/entity_last_modification.lua

### Getting Entity Last Modification in Unix
you also can generate it in unix 

codeof:exemples/last_modification/entity_last_modification_in_unix.lua

### Hashing 
You can generate assignature of anything you want  with all the hash functions

#### Generating Sha from string
Will generate a sha256 assignature of a string 
codeof:exemples/Hashing/generate_sha_from_string.lua

#### Generating Sha from file
Will generate a sha256 assignature of a file
codeof:exemples/Hashing/generate_sha_from_file.lua

#### Generating Sha from folder by content
Will generate a sha256 assignature of a folder based on content
codeof:exemples/Hashing/generate_sha_from_folder_by_content.lua


#### Generating Sha from folder by last modification
Will generate a sha256 assignature of a folder based on last modification
codeof:exemples/Hashing/generate_sha_from_folder_by_last_modification.lua

### Hasher
if you need to combine a lot of different entries, you can use the DtwHasher object

codeof:exemples/Hashing/Hasher.lua

### Path  
Path its a algo class to handle path logics

#### Basic path extraction 
codeof:exemples/Path/basic_path.lua

#### Extracting Sub dirs 
You also can extract sub dirs, by passing start and end keyworks (-1 its the last, -2 the second last)

codeof:exemples/Path/path_get_dir_at.lua


#### Basic Path Insertions 

#### Set Dir 
codeof:exemples/Path/path_set_dir.lua

#### Set Name
codeof:exemples/Path/path_set_name.lua

#### Set Extension
codeof:exemples/Path/path_set_extension.lua


#### Inserting dirs at after point
codeof:exemples/Path/path_insert_dir_after.lua

#### Inserting dirs at before point
codeof:exemples/Path/path_insert_dir_before.lua

#### Inserting dirs at index
codeof:exemples/Path/path_insert_dir_at_index.lua

#### Replacing Dirs
codeof:exemples/Path/path_replace_dirs.lua



### Transaction
Transactions its a way to write actions in a atomic way, preventing crashing operations 

codeof:exemples/Transaction/basic_transaction.lua

#### Dumping Transaction to json
you also can store a transaction into a json, to load it in the future, or in a diferent 
os
codeof:exemples/Transaction/dump_transaction_to_json.lua


#### Loading a transactiion from json 
these example loads a transaction from a json file 


codeof:exemples/Transaction/load_transaction.lua


### Resources 
Resources it's a way to manipulate files and folders, as dictionarys, they are usefull for  
larger storage models

#### Basic Resource in Lua
codeof:exemples/resource/basic_resource.lua

Resources can be files or folders, that are automaticly determined based on the code behavior
for example, if you use the function "get_value" the lib understand that its a file , if you type 
sub resource, it understand that its a folder 

#### Getting a value from a file
in these example we are getting a value from a faile 

codeof:exemples/resource/retriving_values.lua

#### Getting  a value from a sub resource
In these example we are getting a value from a sub resource directaly

codeof:exemples/resource/retriving_values_from_sub_resource.lua

#### Setting Values in Sub Resource 

codeof:exemples/resource/setting_values_in_sub_resource.lua

#### Destroying a sub resource
you also can destroy a resource

codeof:exemples/resource/destroying_values.lua


#### Listage 
there is a lot of ways to list into  files in lua,based on your style of coding
codeof:exemples/resource/list.lua

#### Each 
if you prefer  a more functional way ,you can use the each method for basic iteration 

codeof:exemples/resource/each.lua

#### Map 
you also can map the resources retriving a generated struct

codeof:exemples/resource/map.lua

#### Find 
its possible to find elements based on functions to

codeof:exemples/resource/find.lua

#### Filter 
and you can filter elements, in these example we are filtering based on file exist

codeof:exemples/resource/filter.lua

#### Custom sub Resources
With Custom sub resources , you can generate customizible elements to your resources
making elements based onyour necessity

#### Sub Resource Now 

will create a sub resource with the name of the current time
codeof:exemples/resource/sub_resource_now.lua

#### Sub Resource Now in Unix

Will create a resource with the current unix time
codeof:exemples/resource/sub_resource_now_in_unix.lua

#### Sub Resource Random 
Will create a resource with a random name

codeof:exemples/resource/sub_resource_random.lua

#### Sub Resource Next 
will creeate a resource with the given size of mothers folder

codeof:exemples/resource/sub_resource_next.lua

### Schemas
Schemas its a way to emulate relational behavior inside resource system 
its super usefull for larger storage models, int contemplates, insertions and primary keys
(joins  maybe will be avaliable in the future)

#### Basic Schema Insertion 

codeof:exemples/schema/basic_insertion.lua

#### Finding By Primary key
you also can find elements based on their primary key

codeof:exemples/schema/finding_by_primary_key.lua

#### Destroying
the schema destruction grants the system integridy, so all the entity and its keys, will be destroyed 

codeof:exemples/schema/destroyng_user.lua

#### Schema Listage
You can also list elements of the schema easly
codeof:exemples/schema/listing.lua

#### Schema Each 
if you prefer an functional aproact , each its also available 

codeof:exemples/schema/foreach.lua

#### Schema Map 
if you need to construct a struct of your schema ( to return in web apis for example)map its also available
codeof:exemples/schema/map.lua

#### Schema Filter
you also can aply filtrage in schemas

codeof:exemples/schema/filter.lua


### Trees and Tree Parts

Trees and Tree parts are a way to manage files in a one dimension list 

#### Creating a Tree
in these example, we create a tree
codeof:exemples/Tree/creating_a_tree.lua


### Modifying a Tree
Here we set all txt extension to py extension of a loaded tree
codeof:exemples/Tree/modifying_extension.lua

#### Map Tree
You also can map trees , to create custom objects list derived from tree parts 

codeof:exemples/Tree/map.lua

#### Count Tree
or you can count tree parts that fits conditions
codeof:exemples/Tree/count.lua
`
`### Hardwar Operators
These tree actions type on tree behave different on each other
#### Hardware Write 
Hardware Write will make the changes ,ignoring previews existence
for example ,if a file its "a.txt"  and you set the path to "b.txt" it will
create a new file "b.txt" ignoring a.txt, but if you set the content of a.txt without 
modifying the path, it will overwrite the "a.txt"

codeof:exemples/Tree/hardware_write.lua

#### Hardware Modify
Hardware Modify will consider previews path, and in the same example, if you change the path
from "a.txt" to "b.txt" it will rename the file
codeof:exemples/Tree/hardware_modify.lua

#### Hardware Remove
These directive will remove the given tree part that you typed
codeof:exemples/Tree/hardware_remove.lua

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

codeof:exemples/Locker/lock_file.lua

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
