


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local random = dtw.newRandonizer()

local token = random.generate_token(30)
local token2 = random.generate_token(30)

print(token)
print(token2)