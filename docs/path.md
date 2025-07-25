
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

