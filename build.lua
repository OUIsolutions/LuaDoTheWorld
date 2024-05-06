

local RECONSTRUCT = false
local SIDE_EFFECT = "target"

os.execute("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  clib/main.c")



local dtw = require("luaDoTheWorld/luaDoTheWorld")
local concat_path = true;
local tests  = dtw.list_dirs("tests",concat_path)

---@param inputstr string 
---@param sep string
---@returns string[]
local function slipt (inputstr, sep)

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
    local file_path = t..name..".lua"


    local expected_file_path = t.."expected.txt"
    local target_copy  = SIDE_EFFECT.."copy"
    
    local hasher = dtw.newHasher()
    hasher.digest_folder_by_content(SIDE_EFFECT)
    local start_assignature = tostring(hasher)

    
    dtw.copy_any_overwriting(SIDE_EFFECT,target_copy)


    local expected_code = dtw.load_file(expected_file_path)
    if expected_code == nil or RECONSTRUCT then 
        expected_code = io.popen("lua "..file_path,"r"):read()
        dtw.write_file(expected_file_path,expected_code)
    end 


    local expected_code = dtw.load_file(expected_file_path)
    

    local comparation_result = io.popen("lua "..file_path,"r"):read()
    if expected_code ~=comparation_result then
        print(
            "on file "..file_path
            .." was expecting:'"..expected_code.."'\n"
            .."but got:'"..comparation_result.."'")
        os.exit(1)
    end


    
    --validate_commad_result(result)
end 
