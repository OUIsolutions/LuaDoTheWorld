

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

local sha = dtw.generate_sha_from_folder_by_last_modification("tests/target/test_dir")
print(sha)
~~~


#### Generating Sha from folder by last modification
Will generate a sha256 assignature of a folder based on last modification

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_folder_by_content("tests/target/test_dir")
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
 
~~