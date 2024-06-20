

Lua DoTheWorld its a Lua Lib to manipulate IO in all possible ways, providing 
from basic functions like, read/write/move/copy to listage and listage recurisively
to highly abstracted functions like transactions, hashing, seting primary keys, etc..

LuaDoTheWorld it's a wrapper of the original doTHeWorld lib that can be found in these repo

[DoTheWorld Link](https://github.com/OUIsolutions/DoTheWorld)



# Basics

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
