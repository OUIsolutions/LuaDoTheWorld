
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