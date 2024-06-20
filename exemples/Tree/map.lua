local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local result = tree.map(function (element)

	return {path=element.path.get_full_path(),content=element.get_value()}

end)

local size = tree.get_size()
for i=1,size do
    local current  = result[i]
    print("========================")
    print("path",current.path)
    print("content",current.content)

end
