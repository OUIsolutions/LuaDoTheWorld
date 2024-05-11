
---@class DtwBytes 
---@field size number
---@field get_byte_at_index fun(index:number):number

---@class DtwHasher
---@field digest fun(value:string | number | boolean | DtwBytes )
---@field digest_file fun(source:string)
---@field digest_folder_by_content fun(source:string)
---@field digest_folder_by_last_modification fun(source:string
---@field get_value fun()


---@class DtwResource
---@field sub_resource fun(str:string) :DtwResource
---@field sub_resource_next fun(str:string) :DtwResource
---@field sub_resource_now fun(str:string) :DtwResource
---@field sub_resource_now_in_unix fun(str:string) :DtwResource
---@field __index fun(str:string) : number ,DtwResource
---@field get_value fun():string | number | boolean | nil | DtwBytes
---@field set_value fun(value:string | number | boolean | DtwBytes ) 
---@field commit fun()  apply the modifications
---@field lock fun() lock the resource from other process 
---@field unlock fun()
---@field unload fun() unload the content 
---@field get_path fun() :string
---@field get_name fun() :string
---@field get_extension fun() :string
---@field get_name_without_extension fun() :string
---@field get_dir fun() :string
---@field foreach fun(callback :fun(element:DtwResource))
---@field set_extension fun(extension:string)
---@field list fun(): DtwResource[]
---@field destroy fun()


---@class DtwModule
---@field copy_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field copy_any_merging   fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_overwriting fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field move_any_merging fun(src:string,dest:string):boolean returns true if the operation were ok otherwise false
---@field remove_any fun(src:string):boolean returns true if the operation were ok otherwise false
---@field base64_encode_file fun(src:string):string transform file into base64 
---@field base64_encode fun(value:string | number | boolean | DtwBytes):string transform content into base64
---@field base64_decode fun(value:string): string | DtwBytes retransform base64 into normal value 
---@field list_files fun(src:string):string[] 
---@field list_dirs fun(src:string):string[] 
---@field list_all fun(src:string):string[] 
---@field list_files_recursively fun(src:string):string[] 
---@field list_dirs_recursively fun(src:string):string[] 
---@field list_all_recursively fun(src:string):string[] 
---@field load_file fun(src:string):string | DtwBytes
---@field write_file fun(src:string,value:string | number | boolean | DtwBytes)
---@field is_byte fun(value:any):boolean returns if a value is a byte
---@field newResource fun(src:string):DtwResource
---@field generate_sha fun(value:string | number | boolean | DtwBytes):string 
---@field generate_sha_from_file fun(src:string):string
---@field generate_sha_from_folder_by_content fun(src:string):string
---@field generate_sha_from_folder_by_last_modification fun(src:string):string
---@field newHasher fun():DtwHasher
---@field isdir fun():boolean
---@field isfile fun():boolean
---@field isfile_byte fun():boolean


local info = debug.getinfo(1, "S")
local path = info.source:match("@(.*/)") or ""




local lib_path = ''

if os.getenv("HOME") then
    lib_path = path.."luaDoTheWorld_clib.so"
else
    perror("undefined os") 
end 

local load_lua = package.loadlib(lib_path, "load_lua")

---@type DtwModule
local lib = load_lua()

return lib
