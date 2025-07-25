

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