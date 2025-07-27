local dtw = require("luaDoTheWorld/luaDoTheWorld")
CACHE_DIR = "./main_cache/"
CACHE_NAME = "web_curl"

dtw.clear_old_cache({
    cache_dir = CACHE_DIR,
    cache_name= CACHE_NAME,
    expiration = 30,  -- 30 seconds
})

local URL = "https://example.com/"
local cached_data = dtw.execute_cache({
    expiration = 30,  --30 seconds
    cache_name= CACHE_NAME,
    cache_dir = CACHE_DIR,
    input=URL ,
    callback = function()
        print("retriving data from URL: " .. URL)
        os.execute("curl " .. URL .. " -o temp")
        local content =  dtw.load_file("temp")
        dtw.remove_any("temp")
        return content
    end
})
print(cached_data)