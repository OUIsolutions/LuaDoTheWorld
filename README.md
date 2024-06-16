

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
