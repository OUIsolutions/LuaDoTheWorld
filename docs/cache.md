# 💾 Cache System Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Cache-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Complete Guide** for intelligent caching with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to cache expensive operations to boost performance
- ✅ Understanding pure vs impure functions and their caching strategies
- ✅ How to use both function-based and execution-based caching
- ✅ How to manage cache timeouts and invalidation
- ✅ How to clean up old cache entries automatically
- ✅ Best practices for efficient cache management

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🎯 Why Use Caching?

Caching stores results of expensive operations (network requests, file processing, computations) so they don't need to be repeated. This can **dramatically speed up** your applications!

**❌ Without Cache (Slow):**
```lua
-- Downloads the same file every time!
function get_webpage(url)
    os.execute("curl " .. url .. " -o temp")
    return dtw.load_file("temp")
end

local content1 = get_webpage("https://example.com")  -- Downloads (2s)
local content2 = get_webpage("https://example.com")  -- Downloads AGAIN! (2s) 😰
```

**✅ With Cache (Fast):**
```lua
-- Downloads once, then reuses the result!
local cached_get_webpage = dtw.create_cache_function({
    expiration = 300,  -- 5 minutes
    cache_dir = "./web_cache/",
    callback = function(url)
        os.execute("curl " .. url .. " -o temp")
        return dtw.load_file("temp")
    end
})

local content1 = cached_get_webpage("https://example.com")  -- Downloads (2s)
local content2 = cached_get_webpage("https://example.com")  -- Uses cache! (0.1s) 🚀
```

---

## 🧠 Pure vs Impure Functions - The Foundation of Smart Caching

Understanding function purity is **crucial** for effective caching. This determines how long you should cache results!

### 🟢 Pure Functions (Perfect for Infinite Caching)

**Pure functions** always return the same output for the same input. **Cache them forever!**

**Examples of Pure Functions:**
- Mathematical calculations (fibonacci, factorials)
- String transformations (base64 encoding)
- File hashing (SHA256 of file content)
- Data transformations (JSON parsing)

```lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")
local cached_fibonacci = nil
-- ✅ PURE: Mathematical calculations
cached_fibonacci = dtw.create_cache_function({
    expiration = dtw.INFINITY,  -- Never expires - math never changes!
    cache_dir = "./main_cache/",
    cache_name="Fibonacci",
    handle_errors = false,
    callback =  function (n)
        if n <= 1 then
            return n
        else
            return cached_fibonacci(n - 1) + cached_fibonacci(n - 2)
        end
    end
})
function Fibonacci(number)

    local last_number_str = dtw.load_file("last_fibonacci.txt")
    local last_number = tonumber(last_number_str) or 0
    -- use these to avoid recursion limit issues
    for  i =last_number,number do 
        cached_fibonacci(i)
    end 
    return cached_fibonacci(number)
end


print(Fibonacci(1000)) -- This will print the 1000th Fibonacci number
```

### 🟡 Impure Functions (Need Time-Based Caching)

**Impure functions** might return different results over time. **Cache them with appropriate expiration!**

**Examples of Impure Functions:**
- Web API calls (data changes frequently)
- Weather data (updates hourly)
- Stock prices (changes constantly)
- File timestamps (changes when file is modified)

```lua
-- ⚠️ IMPURE: Web content changes over time
local cached_web = dtw.create_cache_function({
    expiration = 300,  -- 5 minutes - good balance
    cache_dir = "./web_cache/",
    callback = function(url)
        os.execute("curl " .. url .. " -o temp")
        return dtw.load_file("temp")
    end
})

-- ⚠️ IMPURE: Weather changes frequently
local cached_weather = dtw.create_cache_function({
    expiration = 1800,  -- 30 minutes - weather updates
    cache_dir = "./weather_cache/",
    callback = function(city)
        return get_weather_api(city)
    end
})
```

---

## 🔧 Cache Functions - Two Powerful Approaches

LuaDoTheWorld provides **two main caching approaches** for different use cases:

### 1. Function-Based Caching (`create_cache_function`)

**Best for:** Reusable functions you call multiple times

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local cached_function = dtw.create_cache_function({
    expiration = 60,                    -- Cache for 60 seconds
    cache_dir = "./my_cache/",          -- Directory to store cache files
    callback = function(input)
        print("Expensive operation with:", input)
        -- Your expensive operation here
        return "Result for: " .. input
    end
})

-- Usage
local result1 = cached_function("hello")  -- Executes function
local result2 = cached_function("hello")  -- Uses cache!
local result3 = cached_function("world")  -- Different input = new execution
```

### 2. Execution-Based Caching (`execute_cache`)

**Best for:** One-time operations or complex cache invalidation scenarios

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local cached_data = dtw.execute_cache({
    expiration = 30,                    -- 30 seconds
    cache_name = "web_data",            -- Unique name for this cache
    cache_dir = "./web_cache/",         -- Directory to store cache
    input = "https://example.com/",     -- Input that determines cache uniqueness
    callback = function()
        print("Fetching data from web...")
        os.execute("curl https://example.com/ -o temp")
        local content = dtw.load_file("temp")
        dtw.remove_any("temp")
        return content
    end
})

print(cached_data)
```

---

## ⏰ Cache Timeout Strategies

Choose the right timeout based on how frequently your data changes:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- ♾️ INFINITE: For pure functions (never changes)
local permanent_cache = dtw.create_cache_function({
    expiration = dtw.INFINITY,  -- Never expires
    cache_dir = "./permanent/",
    callback = function(x) return x * x end
})

-- ⚡ SHORT: For rapidly changing data (30 seconds)
local short_cache = dtw.create_cache_function({
    expiration = 30,
    cache_dir = "./short/",
    callback = function(url) return download_live_data(url) end
})

-- 🕐 MEDIUM: For moderately stable data (1 hour)
local medium_cache = dtw.create_cache_function({
    expiration = 3600,
    cache_dir = "./medium/",
    callback = function(city) return get_weather(city) end
})

-- 📅 LONG: For rarely changing data (24 hours)
local long_cache = dtw.create_cache_function({
    expiration = 86400,
    cache_dir = "./long/",
    callback = function(coords) return get_timezone(coords) end
})
```

---

## 🔄 Advanced Cache Invalidation

Sometimes you need to force cache updates even before expiration:

### Force Cache Invalidation with `always_execute`

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Normal cache usage
local token = dtw.execute_cache({
    expiration = dtw.INFINITY,
    cache_dir = "./auth_cache/",
    cache_name = "user_token",
    input = {username, password},
    callback = function()
        return create_auth_token(username, password)
    end
})

-- If token is invalid, force regeneration
if not validate_token(token) then
    print("Token invalid! Creating new one...")
    local new_token = dtw.execute_cache({
        expiration = dtw.INFINITY,
        cache_dir = "./auth_cache/",
        cache_name = "user_token",
        input = {username, password},
        always_execute = true,  -- 🔥 Force cache invalidation!
        callback = function()
            return create_auth_token(username, password)
        end
    })
end
```

### Smart Cache Signatures with File Dependencies

For operations that depend on files, include file content or modification time in the cache signature:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local cached_compilation = dtw.create_cache_function({
    expiration = dtw.INFINITY,
    cache_dir = "./compile_cache/",
    callback = function(props)
        print("Compiling:", props.filename)
        os.execute("gcc " .. props.filename .. " -o temp")
        local content = dtw.load_file("temp")
        dtw.remove_any("temp")
        return content
    end
})

-- Smart compilation with dependency tracking
function compile_with_dependencies(filename, output)
    local hasher = dtw.newHasher()
    
    -- Include all source files in signature
    local files = dtw.list_files_recursively(".", true)
    for _, file in ipairs(files) do
        if dtw.ends_with(file, ".c") or dtw.ends_with(file, ".h") then
            hasher.digest_file(file)  -- File content affects cache
        end
    end
    
    local dir_signature = hasher.get_value()
    
    -- Cache becomes invalid if ANY source file changes! 🧠
    local content = cached_compilation({
        filename = filename,
        dir_signature = dir_signature
    })
    
    dtw.write_file(output, content)
end
```

---

## 🧹 Cache Management & Cleanup

Keep your cache directories clean and efficient:

### Automatic Cleanup with `clear_old_cache`

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Clear old entries before using cache
dtw.clear_old_cache({
    cache_dir = "./web_cache/",
    cache_name = "api_calls",
    expiration = 3600  -- Remove entries older than 1 hour
})

-- Then use your cache normally
local cached_api = dtw.create_cache_function({
    expiration = 1800,  -- 30 minutes
    cache_dir = "./web_cache/",
    callback = function(endpoint)
        return call_api(endpoint)
    end
})
```

### Periodic Cleanup Strategies

```lua
-- Clear very old entries (1 week)
local ONE_WEEK = 7 * 24 * 60 * 60
dtw.clear_old_cache({
    cache_dir = "./compile_cache/", 
    cache_name = "builds",
    expiration = ONE_WEEK
})

-- Clear cache entries older than 1 day
local ONE_DAY = 24 * 60 * 60
dtw.clear_old_cache({
    cache_dir = "./downloads/",
    cache_name = "files", 
    expiration = ONE_DAY
})
```

---

## 💡 Real-World Examples

### Example 1: Web Content Caching with Cleanup

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Setup cache with automatic cleanup
local CACHE_DIR = "./web_cache/"
local CACHE_NAME = "api_data"

dtw.clear_old_cache({
    cache_dir = CACHE_DIR,
    cache_name = CACHE_NAME,
    expiration = 1800  -- Clear entries older than 30 minutes
})

-- Create cached web fetcher
local get_web_content = dtw.create_cache_function({
    expiration = 900,  -- 15 minutes
    cache_dir = CACHE_DIR,
    callback = function(url)
        print("🌐 Fetching:", url)
        os.execute("curl -L '" .. url .. "' -o temp")
        local content = dtw.load_file("temp")
        if not content then
            error("Failed to fetch: " .. url)
        end
        dtw.remove_any("temp")
        return content
    end
})

-- Usage
local github_data = get_web_content("https://api.github.com/users/octocat")
local same_data = get_web_content("https://api.github.com/users/octocat")  -- From cache! ⚡
```

### Example 2: Fibonacci with Incremental Caching

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Create cached fibonacci function
local cached_fibonacci = dtw.create_cache_function({
    expiration = dtw.INFINITY,  -- Math never changes!
    cache_dir = "./math_cache/",
    callback = function(n)
        if n <= 1 then
            return n
        else
            return cached_fibonacci(n - 1) + cached_fibonacci(n - 2)
        end
    end
})

-- Smart fibonacci that avoids recursion limits
function fibonacci(number)
    -- Pre-calculate to avoid deep recursion
    for i = 0, number do
        cached_fibonacci(i)
    end
    return cached_fibonacci(number)
end

print(fibonacci(1000))  -- Calculates once, then cached forever! 🚀
```

### Example 3: Token-Based Authentication with Cache Invalidation

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local CACHE_DIR = "./auth_cache/"
local CACHE_NAME = "user_tokens"

-- Function to get user properties with smart token caching
function get_user_props(username, password)
    -- Try to get cached token
    local token = dtw.execute_cache({
        expiration = dtw.INFINITY,
        cache_dir = CACHE_DIR,
        cache_name = CACHE_NAME,
        input = {username, password},
        callback = function()
            print("🔑 Creating new token...")
            return create_auth_token(username, password)
        end
    })
    
    -- Try to use the token
    local ok, user_props = pcall(get_user_data, token)
    
    if ok then
        return user_props
    end
    
    -- Token invalid! Force regeneration
    print("❌ Token invalid! Regenerating...")
    local new_token = dtw.execute_cache({
        expiration = dtw.INFINITY,
        cache_dir = CACHE_DIR,
        cache_name = CACHE_NAME,
        input = {username, password},
        always_execute = true,  -- Force cache invalidation
        callback = function()
            print("🔑 Creating new token...")
            return create_auth_token(username, password)
        end
    })
    
    return get_user_data(new_token)
end
```

### Example 4: File Processing with Content-Based Invalidation

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Cache image processing (content-based invalidation)
local cached_process_image = dtw.create_cache_function({
    expiration = dtw.INFINITY,  -- Processing is deterministic
    cache_dir = "./image_cache/",
    callback = function(props)
        local input_file = props.input_file
        local operations = props.operations
        local image_content = props.image_content
        
        print("🖼️ Processing image:", input_file)
        
        -- Write to temp file for processing
        local temp_input = "temp_" .. os.time() .. ".jpg"
        dtw.write_file(temp_input, image_content)
        
        -- Process with ImageMagick
        local cmd = "convert " .. temp_input
        for _, op in ipairs(operations) do
            cmd = cmd .. " " .. op
        end
        cmd = cmd .. " temp_output.png"
        
        os.execute(cmd)
        local result = dtw.load_file("temp_output.png")
        
        -- Cleanup
        dtw.remove_any(temp_input)
        dtw.remove_any("temp_output.png")
        
        return result
    end
})

-- Smart wrapper that includes file content in cache signature
function process_image_with_cache(input_file, operations, output_file)
    -- Include file content in cache signature (content changes = cache invalidation!)
    local image_content = dtw.load_file(input_file)
    
    local processed = cached_process_image({
        input_file = input_file,
        operations = operations,
        image_content = image_content  -- Content tracked as dependency! 🎯
    })
    
    dtw.write_file(output_file, processed)
    print("✅ Image processed and saved to:", output_file)
end

-- Usage
process_image_with_cache("photo.jpg", {"-resize 800x600", "-blur 0x1"}, "processed.png")
```

---

## ⚠️ Best Practices

### ✅ Do's
- 🎯 **Use infinite expiration for pure functions** (math, transformations)
- 🕐 **Set appropriate timeouts** based on data freshness requirements
- 🔄 **Include all dependencies** in cache signatures (file content, timestamps)
- 🧹 **Use `clear_old_cache` regularly** to prevent disk space issues
- 📁 **Use descriptive cache directory names** for organization
- 🔍 **Handle errors in callbacks** - they will be cached too!
- 📊 **Monitor cache hit rates** to optimize performance

### ❌ Don'ts
- ⚠️ **Don't cache functions with side effects** (database writes, file modifications)
- 💾 **Don't use very short cache timeouts** - causes unnecessary overhead
- 🔄 **Don't forget file modification tracking** when processing files
- 🚫 **Don't cache sensitive data** without encryption
- ⏰ **Don't use infinite timeout** for data that changes over time
- 🗂️ **Don't use the same cache_name** for different data types

---

## 📚 Complete Function Reference

| Function | Purpose | Parameters | Example |
|----------|---------|------------|---------|
| `dtw.create_cache_function(config)` | Create a reusable cached function | `{expiration, cache_dir, callback}` | `dtw.create_cache_function({expiration=60, cache_dir="./cache/", callback=func})` |
| `dtw.execute_cache(config)` | Execute single operation with caching | `{expiration, cache_dir, cache_name, input, callback, always_execute?}` | `dtw.execute_cache({expiration=30, cache_dir="./cache/", cache_name="web", input=url, callback=func})` |
| `dtw.clear_old_cache(config)` | Remove expired cache entries | `{cache_dir, cache_name, expiration}` | `dtw.clear_old_cache({cache_dir="./cache/", cache_name="web", expiration=3600})` |
| `dtw.INFINITY` | Constant for infinite cache timeout | N/A | `expiration = dtw.INFINITY` |
| `dtw.newHasher()` | Create hasher for complex signatures | N/A | `hasher = dtw.newHasher()` |
| `hasher.digest(data)` | Add data to signature hash | `data: string` | `hasher.digest("hello")` |
| `hasher.digest_file(path)` | Add file content to signature hash | `path: string` | `hasher.digest_file("file.txt")` |
| `hasher.get_value()` | Get final hash signature | N/A | `signature = hasher.get_value()` |

### Configuration Parameters

**For `create_cache_function`:**
- `expiration`: Cache timeout in seconds (or `dtw.INFINITY`)
- `cache_dir`: Directory to store cache files
- `callback`: Function to execute when cache misses

**For `execute_cache`:**
- `expiration`: Cache timeout in seconds (or `dtw.INFINITY`) 
- `cache_dir`: Directory to store cache files
- `cache_name`: Unique name for this cache entry
- `input`: Input data that determines cache uniqueness
- `callback`: Function to execute when cache misses
- `always_execute`: *(optional)* Force cache invalidation if `true`

**For `clear_old_cache`:**
- `cache_dir`: Directory containing cache files
- `cache_name`: Name of cache entries to clean
- `expiration`: Remove entries older than this (seconds)

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at example scripts in `/examples/cache/` 
- 🐛 Report issues on our GitHub repository
- 💡 **Remember:** When in doubt, include more context in your cache signatures!

---

## 🚀 Performance Tips

1. **📊 Monitor Your Cache** - Log cache hits vs misses to optimize
2. **🗂️ Organize Cache Directories** - Use separate dirs for different data types
3. **🧹 Regular Cleanup** - Use `clear_old_cache` in your startup scripts
4. **🎯 Smart Signatures** - Include all relevant dependencies in cache keys
5. **⚡ Infinite Pure Functions** - Cache mathematical operations forever
6. **🕐 Time-Based Impure** - Set appropriate timeouts for changing data

---

![Footer](https://img.shields.io/badge/Happy-Caching!-ff69b4?style=flat-square&logo=heart)
