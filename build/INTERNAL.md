

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

