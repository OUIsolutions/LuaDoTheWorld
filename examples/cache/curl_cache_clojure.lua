local dtw = require("luaDoTheWorld/luaDoTheWorld")
CACHE_DIR = "./main_cache/"
CACHE_NAME = "web_curl"

dtw.clear_old_cache({
    cache_dir = CACHE_DIR,
    cache_name= CACHE_NAME,
    expiration = 30,  -- 30 seconds
})

local curl_cache = dtw.create_cache_function({
    expiration = 30,  --30 seconds
    cache_name= CACHE_NAME,
    cache_dir = CACHE_DIR,
    callback = function(url)
        print("retriving data from URL: " .. url)
        os.execute("curl " .. url .. " -o temp")
        local content =  dtw.load_file("temp")
        dtw.remove_any("temp")
        return content
    end
})
local data = curl_cache("https://example.com/")
print(data)