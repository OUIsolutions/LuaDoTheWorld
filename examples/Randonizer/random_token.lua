
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local randonizer = dtw.newRandonizer()
local size = 20
local token1 = randonizer.generate_token(size)
local token2 = randonizer.generate_token(size)

print(token1)
print(token2)
