
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