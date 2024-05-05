


os.execute("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  clib/main.c")



local dtw = require("luaDoTheWorld/luaDoTheWorld")
local concat_path = true;
local tests  = dtw.list_dirs("tests",concat_path)

---@param inputstr string 
---@param sep string
---@returns string[]
local function slipt (inputstr, sep)
    if sep == nil then
            sep = "%s"
    end
    local t={}
    for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
            table.insert(t, str)
    end
    return t
end





for i, t in ipairs(tests) do 
    local name = slipt(t,"/")[2]
    if name == nil then 
        print("name of test "..t.."not provide")
        os.exit(1)
    end 
    local file = t..name
    local comand = "valgrind lua "..file
    local result = capture_output(comand)
    print("xxxxxxxxxxxxxxxxxxxxxx")
    print(result)
    --validate_commad_result(result)
end 
