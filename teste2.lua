
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local v = dtw.load_file("teste.jpg")

local i = 1 
local current = v[i]
local repetitions = 0
while current  do

    local old = v[i-1]
    current = v[i]

    if old == current then
        repetitions = repetitions+1
    end
    i = i+1
end
print("total",i)
print("repetitions",repetitions)