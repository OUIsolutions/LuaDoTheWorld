

### Trees and Tree Parts

Trees and Tree parts are a way to manage files in a one dimension list

#### Creating a Tree
in these example, we create a tree

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree()
local a = tree.newTreePart_empty("tests/target/Tree/a.txt")
a.set_value("content of a")
a.hardware_write()
local b = tree.newTreePart_empty("tests/target/Tree/b.txt")
a.set_value("content of b")
a.hardware_write()

tree.commit()


~~~


### Modifying a Tree
Here we set all txt extension to py extension of a loaded tree

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

tree.each(function (element)

	if element.path.get_extension()== "txt" then
		element.path.set_extension("py")
	end
	element.hardware_modify()
end)

tree.commit()
~~~

#### Map Tree
You also can map trees , to create custom objects list derived from tree parts


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local result,size = tree.map(function (element)

	return {path=element.path.get_full_path(),content=element.get_value()}

end)
for i=1,size do
    local current  = result[i]
    print("========================")
    print("path",current.path)
    print("content",current.content)

end

~~~

#### Count Tree
or you can count tree parts that fits conditions

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local size = tree.count(function (element)

	if element.path.get_extension() == "py" then
		return true
	end
end)


print(size)
~~~
`
`### Hardwar Operators
These tree actions type on tree behave different on each other
#### Hardware Write
Hardware Write will make the changes ,ignoring previews existence
for example ,if a file its "a.txt"  and you set the path to "b.txt" it will
create a new file "b.txt" ignoring a.txt, but if you set the content of a.txt without
modifying the path, it will overwrite the "a.txt"


~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
        return true;
	end
end)
target.path.set_name("new_name.txt")
target.hardware_write()

tree.commit()


~~~

#### Hardware Modify
Hardware Modify will consider previews path, and in the same example, if you change the path
from "a.txt" to "b.txt" it will rename the file

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
        return true;
	end
end)
target.path.set_name("new_name.txt")
target.hardware_modify()

tree.commit()


~~~

#### Hardware Remove
These directive will remove the given tree part that you typed

~~~lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function (element)

	if element.path.get_name() == "a.txt" then
        return true;
	end
end)

target.path.set_name("new_name.txt")
target.hardware_remove()

tree.commit()


~~~
