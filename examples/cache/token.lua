-- Import the LuaDoTheWorld library
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Set up cache configuration
CACHE_DIR = "./main_cache/"    -- Directory where cache files will be stored
CACHE_NAME = "token_creation"  -- Name of our specific cache

-- DEMO: CACHING SYSTEM AND CACHE INVALIDATION

--------------------------------------------------
-- SIMULATED BACKEND FUNCTIONS
--------------------------------------------------

-- This function simulates creating a token from username and password
-- In a real application, this might call an API or database
function fake_create_token(username, password)
    print("Creating new token for user: " .. username)
    
    -- Simple counter to generate different tokens each time
    if not Incremented_token then
        Incremented_token = 0
    end
    
    local fake_token = "fake_token_" .. Incremented_token
    Incremented_token = Incremented_token + 1
    
    return fake_token
end

-- This function simulates fetching user properties using a token
-- In a real application, this might verify a token with an authentication server
function fake_get_user_props(token)
    print("Attempting to get user properties with token: " .. token)
    
    -- Simulate an invalid token scenario (first token will always fail)
    if token == "fake_token_0" then
        print("❌ Error: Invalid token")
        error("Token " .. token .. " is not valid")
    end
    
    print("✅ Token valid, returning user properties")
    return {
        name = "John Doe",
        email = "john@example.com"
    }
end

--------------------------------------------------
-- MAIN FUNCTION WITH CACHE USAGE
--------------------------------------------------

-- Function that gets user properties with caching mechanism
function get_user_props(username, password)
    print("\n==== ATTEMPTING TO GET USER PROPERTIES ====")
    
    -- STEP 1: Try to get token from cache or create a new one if not cached
    print("STEP 1: Getting token (from cache if available)")
    local token = dtw.execute_cache({
        expiration = dtw.INFINITY,      -- Cache never expires
        cache_dir = CACHE_DIR,          -- Where to store the cache
        cache_name = CACHE_NAME,        -- Name of the cache
        input = {username, password},   -- Input parameters that determine cache uniqueness
        callback = function()           -- Function to call if cache doesn't exist
            return fake_create_token(username, password)
        end
    })
    print("Token retrieved: " .. token)
    
    -- STEP 2: Try to get user properties with the token
    print("\nSTEP 2: Using token to get user properties")
    local ok, user_props = pcall(fake_get_user_props, token)
    
    -- If successful, return the user properties
    if ok then 
        print("Successfully got user properties!")
        return user_props
    end
    
    -- STEP 3: If token is invalid, invalidate cache and create a new token
    print("\nSTEP 3: Token invalid! Invalidating cache and creating new token")
    local token = dtw.execute_cache({
        expiration = dtw.INFINITY,
        cache_dir = CACHE_DIR,
        always_execute = true,         -- This forces cache invalidation
        cache_name = CACHE_NAME,
        input = {username, password},
        callback = function()
            return fake_create_token(username, password)
        end
    })
    print("New token created: " .. token)
    
    -- STEP 4: Try again with the new token
    print("\nSTEP 4: Trying again with new token")
    return fake_get_user_props(token)
end

--------------------------------------------------
-- RUN THE EXAMPLE
--------------------------------------------------

print("===== CACHE SYSTEM DEMONSTRATION =====")
print("This example shows how to use the caching system and handle cache invalidation")
print("We will attempt to get user properties which requires a valid token")
print("The first token will be invalid to demonstrate cache invalidation\n")

-- Get the user properties (will trigger cache invalidation on first run)
local properties = get_user_props("john", "1234")

-- Show the result
print("\n===== RESULT =====")
print("User name: " .. properties.name)
print("User email: " .. properties.email)
print("\nIf you run this script again, it will use the cached token and won't need to recreate it")
