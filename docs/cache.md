# 💾 Cache System Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Cache-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for intelligent caching with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to create cached functions that avoid expensive operations
- ✅ How to understand pure vs impure functions for caching
- ✅ How to set cache timeouts and directories
- ✅ How to use entry signatures for cache invalidation
- ✅ How to clear old cache entries
- ✅ Best practices for cache management

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🎯 Why Use Caching?

Caching stores the results of expensive operations (like network requests, file processing, or compilations) so they don't need to be repeated. This can dramatically speed up your applications!

**Without Cache:**
```lua
-- This downloads the same file every time (slow!)
function get_webpage(url)
    os.execute("curl " .. url .. " -o temp")
    return dtw.load_file("temp")
end

local content1 = get_webpage("https://example.com")  -- Downloads
local content2 = get_webpage("https://example.com")  -- Downloads AGAIN! 😰
```

**With Cache:**
```lua
-- This downloads only once, then reuses the result (fast!)
local cached_get_webpage = dtw.create_cache_function({
    timeout = 300,  -- 5 minutes
    cache_dir = "./web_cache/",
    callback = function(url)
        os.execute("curl " .. url .. " -o temp")
        return dtw.load_file("temp")
    end
})

local content1 = cached_get_webpage("https://example.com")  -- Downloads
local content2 = cached_get_webpage("https://example.com")  -- Uses cache! ⚡
```

---

## 🔧 Basic Cache Function

Create a cached version of any function:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local cached_function = dtw.create_cache_function({
    timeout = 60,                    -- Cache expires after 60 seconds
    cache_dir = "./my_cache/",       -- Directory to store cache files
    callback = function(input)
        print("Expensive operation with:", input)
        -- Your expensive operation here
        return "Result for: " .. input
    end
})

-- First call: executes the function
local result1 = cached_function("hello")  -- Prints: "Expensive operation with: hello"

-- Second call: uses cached result
local result2 = cached_function("hello")  -- No print - uses cache!
```

---

## 🧠 Pure vs Impure Functions

Understanding function purity is crucial for effective caching:

### 🟢 Pure Functions (Perfect for Caching)
**Pure functions** always return the same output for the same input:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local cached_fibonacci = nil

-- ✅ PURE: Mathematical calculations
cached_fibonacci = dtw.create_cache_function({
    timeout = dtw.INFINITY,  -- Never expires - math never changes!
    cache_dir = "./math_cache/",
    callback =  function (n)
        if n <= 1 then
            return n
        else
            return cached_fibonacci(n - 1) + cached_fibonacci(n - 2)
        end
    end
})

-- use these to avoid recursion limit issues
for  i =1,1000 do 
    cached_fibonacci(i)
end 

print(cached_fibonacci(1000)) -- This will print the 1000th Fibonacci number
```

### 🟡 Impure Functions (Need Smart Caching)
**Impure functions** might return different results over time:

```lua
-- ⚠️ IMPURE: Web content changes over time
local cached_web = dtw.create_cache_function({
    timeout = 300,  -- 5 minutes - content might change
    cache_dir = "./web_cache/",
    callback = function(url)
        os.execute("curl " .. url .. " -o temp")
        return dtw.load_file("temp")
    end
})

-- ⚠️ IMPURE: Weather data changes frequently
local cached_weather = dtw.create_cache_function({
    timeout = 1800,  -- 30 minutes - weather updates
    cache_dir = "./weather_cache/",
    callback = function(city)
        return get_weather_api(city)
    end
})
```

---

## 🔑 Entry Signatures for Smart Invalidation

The cache system uses **entry signatures** - unique identifiers based on your function inputs. This ensures cache accuracy:

### Simple Signature (Single Input)
```lua
local cached_func = dtw.create_cache_function({
    timeout = 60,
    cache_dir = "./cache/",
    callback = function(filename)
        -- Entry signature automatically created from "filename" value
        return dtw.load_file(filename)
    end
})

cached_func("file1.txt")  -- Creates cache entry for "file1.txt"
cached_func("file2.txt")  -- Creates different cache entry for "file2.txt"
```

### Complex Signature (Multiple Inputs)
```lua
local cached_compilation = dtw.create_cache_function({
    timeout = dtw.INFINITY,
    cache_dir = "./compile_cache/",
    callback = function(props)
        print("Compiling:", props.filename)
        os.execute("gcc " .. props.filename .. " -o temp")
        local content = dtw.load_file("temp")
        dtw.remove_any("temp")
        return content
    end
})

-- Smart cache invalidation using directory signature
function compile_with_dependencies(filename, output)
    local hasher = dtw.newHasher()
    
    -- Include all source files in signature
    local files = dtw.list_files_recursively(".", true)
    local VALID_EXTENSIONS = {".c", ".h", ".cpp", ".hpp"}
    
    for _, file in ipairs(files) do
        for _, ext in ipairs(VALID_EXTENSIONS) do
            if dtw.ends_with(file, ext) then
                hasher.digest_file(file)  -- File content affects signature
            end
        end
    end
    
    local dir_signature = hasher.get_value()
    
    -- Cache becomes invalid if ANY source file changes!
    local content = cached_compilation({
        filename = filename,
        dir_signature = dir_signature  -- This makes cache smart! 🧠
    })
    
    dtw.write_file(output, content)
end
```

---

## ⏰ Cache Timeout Options

Control how long cache entries remain valid:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- No timeout - cache forever (perfect for pure functions)
local permanent_cache = dtw.create_cache_function({
    timeout = dtw.INFINITY,  -- Never expires
    cache_dir = "./permanent/",
    callback = function(x) return x * x end
})

-- Short timeout - for frequently changing data
local short_cache = dtw.create_cache_function({
    timeout = 30,  -- 30 seconds
    cache_dir = "./short/",
    callback = function(url) return download_data(url) end
})

-- Medium timeout - for moderately stable data
local medium_cache = dtw.create_cache_function({
    timeout = 3600,  -- 1 hour
    cache_dir = "./medium/",
    callback = function(city) return get_weather(city) end
})

-- Long timeout - for rarely changing data
local long_cache = dtw.create_cache_function({
    timeout = 86400,  -- 24 hours
    cache_dir = "./long/",
    callback = function(coords) return get_timezone(coords) end
})
```

---

## 🧹 Cache Management

Keep your cache directories clean and efficient:

### Clear Old Cache Entries
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Clear cache entries older than 1 hour
dtw.clear_cache("./my_cache/", 3600)

-- Clear cache entries older than 1 day
local ONE_DAY = 24 * 60 * 60
dtw.clear_cache("./web_cache/", ONE_DAY)

-- Clear very old entries (1 week)
local ONE_WEEK = 7 * 24 * 60 * 60
dtw.clear_cache("./compile_cache/", ONE_WEEK)
```

### Periodic Cleanup
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Run cleanup before using cache
dtw.clear_cache("./downloads/", 7200)  -- Clear entries older than 2 hours

local cached_download = dtw.create_cache_function({
    timeout = 3600,  -- 1 hour timeout
    cache_dir = "./downloads/",
    callback = function(url)
        print("Downloading:", url)
        os.execute("curl -L " .. url .. " -o temp")
        local content = dtw.load_file("temp")
        dtw.remove_any("temp")
        return content
    end
})
```

---

## 💡 Advanced Examples

### Example 1: Web Content Caching
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Clear old web cache on startup
dtw.clear_cache("./web_cache/", 1800)  -- Clear entries older than 30 minutes

local get_web_content = dtw.create_cache_function({
    timeout = 900,  -- 15 minutes
    cache_dir = "./web_cache/",
    callback = function(url)
        print("Fetching URL:", url)
        dtw.remove_any("temp")
        local ok = os.execute("curl -L " .. url .. " -o temp")
        if not ok then
            error("Failed to fetch URL: " .. url)
        end
        local content = dtw.load_file("temp")
        if not content then
            error("Failed to load content from: " .. url)
        end
        dtw.remove_any("temp")
        return content
    end
})

-- Usage
local content = get_web_content("https://api.github.com/users/octocat")
print("Content length:", #content)
```

### Example 2: File Processing Pipeline
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Cache image processing results
local process_image = dtw.create_cache_function({
    timeout = dtw.INFINITY,  -- Images don't change often
    cache_dir = "./image_cache/",
    callback = function(props)
        local input_file = props.input
        local operations = props.operations
        
        print("Processing image:", input_file)
        
        -- Create signature based on file content AND operations
        local hasher = dtw.newHasher()
        hasher.digest_file(input_file)
        hasher.digest(dtw.serialize_var(operations))
        
        local process_id = hasher.get_value()
        local temp_output = "temp_" .. process_id .. ".png"
        
        -- Apply operations (example)
        local cmd = "convert " .. input_file
        for _, op in ipairs(operations) do
            cmd = cmd .. " " .. op
        end
        cmd = cmd .. " " .. temp_output
        
        os.execute(cmd)
        local result = dtw.load_file(temp_output)
        dtw.remove_any(temp_output)
        
        return result
    end
})

-- Usage
local processed = process_image({
    input = "photo.jpg",
    operations = {"-resize 800x600", "-blur 0x1", "-sharpen 0x2"}
})
```

### Example 3: Database Query Caching
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local cached_query = dtw.create_cache_function({
    timeout = 300,  -- 5 minutes for database queries
    cache_dir = "./db_cache/",
    callback = function(query_params)
        print("Executing database query...")
        
        -- Simulate database query
        local query = query_params.sql
        local params = query_params.params or {}
        
        -- Your database connection and query logic here
        local result = execute_sql_query(query, params)
        
        return result
    end
})

-- Usage
local users = cached_query({
    sql = "SELECT * FROM users WHERE age > ? AND city = ?",
    params = {25, "New York"}
})
```

---

## ⚠️ Best Practices

### ✅ Do's
- 🎯 **Use infinite timeout for pure functions** (math, hashing, etc.)
- 🕐 **Set appropriate timeouts** for impure functions based on data freshness needs
- 🔄 **Include all relevant dependencies** in your entry signatures
- 🧹 **Regularly clear old cache entries** to save disk space
- 📁 **Use descriptive cache directory names** for organization
- 🔍 **Handle errors gracefully** - cached errors are still errors!

### ❌ Don'ts
- ⚠️ **Don't cache functions with side effects** (file writes, API calls with mutations)
- 💾 **Don't use very short cache directories** - causes unnecessary disk I/O
- 🔄 **Don't forget to include file modification times** in signatures when processing files
- 🚫 **Don't cache sensitive data** without proper security considerations
- ⏰ **Don't use infinite timeout** for data that changes over time

---

## 🔧 Cache Configuration Examples

### Development vs Production
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Development: shorter cache for faster iteration
local DEV_MODE = true
local cache_timeout = DEV_MODE and 60 or 3600  -- 1 min vs 1 hour

local cached_build = dtw.create_cache_function({
    timeout = cache_timeout,
    cache_dir = DEV_MODE and "./dev_cache/" or "./prod_cache/",
    callback = function(props)
        -- Your build logic
        return build_project(props)
    end
})
```

### Memory vs Disk Trade-off
```lua
-- For frequently accessed, small results
local memory_friendly_cache = dtw.create_cache_function({
    timeout = 1800,  -- 30 minutes
    cache_dir = "./small_cache/",  -- Small files, frequent access
    callback = function(query)
        return process_small_data(query)
    end
})

-- For rarely accessed, large results
local disk_friendly_cache = dtw.create_cache_function({
    timeout = 86400,  -- 24 hours
    cache_dir = "./large_cache/",  -- Large files, infrequent access
    callback = function(input)
        return process_large_dataset(input)
    end
})
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.create_cache_function(config)` | Create a cached function | `dtw.create_cache_function({timeout=60, cache_dir="./cache/", callback=func})` |
| `dtw.clear_cache(dir, max_age)` | Remove old cache entries | `dtw.clear_cache("./cache/", 3600)` |
| `dtw.INFINITY` | Constant for infinite timeout | `timeout = dtw.INFINITY` |
| `dtw.newHasher()` | Create hasher for signatures | `hasher = dtw.newHasher()` |
| `hasher.digest(data)` | Add data to hash | `hasher.digest("hello")` |
| `hasher.digest_file(path)` | Add file to hash | `hasher.digest_file("file.txt")` |
| `hasher.get_value()` | Get hash signature | `signature = hasher.get_value()` |

---

## 🎯 Complete Real-World Example

Here's a complete example showing a smart build system with caching:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Clear old build cache (keep builds for 1 week)
local ONE_WEEK = 7 * 24 * 60 * 60
dtw.clear_cache("./build_cache/", ONE_WEEK)

-- Create cached build function
local cached_build = dtw.create_cache_function({
    timeout = dtw.INFINITY,  -- Builds are deterministic
    cache_dir = "./build_cache/",
    callback = function(build_config)
        print("Building project with config:", dtw.serialize_var(build_config))
        
        -- Clean previous build
        dtw.remove_any("output")
        
        -- Execute build command
        local cmd = build_config.compiler .. " " .. build_config.source .. " -o output"
        if build_config.flags then
            cmd = cmd .. " " .. table.concat(build_config.flags, " ")
        end
        
        local ok = os.execute(cmd)
        if not ok then
            error("Build failed for: " .. build_config.source)
        end
        
        -- Read build output
        local result = dtw.load_file("output")
        if not result then
            error("Failed to read build output")
        end
        
        dtw.remove_any("output")
        return result
    end
})

-- Smart build function that includes all dependencies
function smart_build(source_file, output_file, compiler, flags)
    -- Create signature from all relevant files
    local hasher = dtw.newHasher()
    
    -- Include main source file
    hasher.digest_file(source_file)
    
    -- Include all header files that might be dependencies
    local headers = dtw.list_files_recursively(".", true)
    for _, file in ipairs(headers) do
        if dtw.ends_with(file, ".h") or dtw.ends_with(file, ".hpp") then
            hasher.digest_file(file)
        end
    end
    
    -- Include compiler and flags in signature
    hasher.digest(compiler or "gcc")
    hasher.digest(dtw.serialize_var(flags or {}))
    
    local dependencies_signature = hasher.get_value()
    
    -- Build with smart caching
    local build_result = cached_build({
        source = source_file,
        compiler = compiler or "gcc",
        flags = flags,
        dependencies = dependencies_signature  -- This makes cache invalidate when deps change!
    })
    
    -- Save to output file
    dtw.write_file(output_file, build_result)
    print("Build completed:", output_file)
end

-- Usage
smart_build("main.c", "program.exe", "gcc", {"-O2", "-Wall"})
```

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at the `curl_cache.lua` and `gcc.lua` examples
- 🐛 Report issues on our GitHub repository
- 💡 Remember: When in doubt, add more context to your entry signatures!

---

![Footer](https://img.shields.io/badge/Happy-Caching!-ff69b4?style=flat-square&logo=heart)
