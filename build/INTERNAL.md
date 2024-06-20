

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
