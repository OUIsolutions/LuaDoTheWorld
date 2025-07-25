

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
