


local dtw = require("luaDoTheWorld/luaDoTheWorld")

local random = dtw.newRandonizer()

local token = random.generate_token(30)
local token2 = random.generate_token(30)
local num1 = random.generate_num(100)
print(token)
print(num1)