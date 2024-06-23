local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local result,size = tree.filter(function (element)

    if(element.get_value() ~=nil)then
        return true
    end

end)
for i=1,size do
    local current = result[i]
    print("path",current.path.get_full_path())
    print("content",current.get_value())
end
