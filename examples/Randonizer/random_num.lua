
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local randonizer = dtw.newRandonizer()
local max = 100
local num = randonizer.generate_num(max)
local num2 = randonizer.generate_num(max)

print(num)
print(num2)
