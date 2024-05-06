


local RECONSTRUCT = false
local SIDE_EFFECT = "target"
local side_effect_copy_path  = SIDE_EFFECT.."copy"


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


local function handle_side_effect(dir,current_assignature) 

    local side_effect_expected_folder = dir.."/side_effect"
    print("created"..side_effect_expected_folder)

    local test_were_predictible = dtw.isdir(side_effect_expected_folder) 
    if not test_were_predictible then
        dtw.copy_any_overwriting(SIDE_EFFECT,side_effect_expected_folder)
    
    else
        local expected_hasher = dtw.newHasher()
        expected_hasher.digest_folder_by_content(side_effect_expected_folder)
        local expected_assignature = tostring(expected_hasher) 
        if expected_assignature ~= current_assignature then
            print("side effect diferent")
            dtw.copy_any_overwriting(side_effect_copy_path,SIDE_EFFECT);
            os.exit(1)
        end
    end




end

print("compiling")

local r,e,code = os.execute("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  clib/main.c")

if code == 1 then
    os.exit(1)
end

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local concat_path = true;
local tests  = dtw.list_dirs("tests",concat_path)



local hasher = dtw.newHasher()
hasher.digest_folder_by_content(SIDE_EFFECT)
local start_assignature = tostring(hasher)

dtw.copy_any_overwriting(SIDE_EFFECT,side_effect_copy_path)


for i, t in ipairs(tests) do 
    
    print("testing: "..t)

    local name = slipt(t,"/")[2]
    if name == nil then 
        print("name of test "..t.."not provide")
        os.exit(1)
    end 
    local file_path = t..name..".lua"


    local expected_file_path = t.."expected.txt"
    



    local expected_code = dtw.load_file(expected_file_path)
    if expected_code == nil or RECONSTRUCT then 
        print(" creatad "..file_path.." ")
        expected_code = io.popen("lua "..file_path,"r"):read()
        if expected_code then
            dtw.write_file(expected_file_path,expected_code)            
        end

    end 


    local expected_code = dtw.load_file(expected_file_path)
    

    local comparation_result = io.popen("lua "..file_path,"r"):read()
    if expected_code ~=comparation_result then
        print(
            "on file "..file_path
            .." was expecting:'"..expected_code.."'\n"
            .."but got:'"..comparation_result.."'")
        --revert any modification    
        dtw.copy_any_overwriting(side_effect_copy_path,SIDE_EFFECT);
        os.exit(1)
    end

    --VERIFY IF SOMETHING WERE MODIFIED
    local verifiyer_haser = dtw.newHasher()
    verifiyer_haser.digest_folder_by_content(SIDE_EFFECT)
    local test_assignature  = tostring(verifiyer_haser)


    --means code generated side effect
    if start_assignature ~= test_assignature then
        handle_side_effect(t,test_assignature)
    end
    
    --validate_commad_result(result)
end 
