
local dtw = require("luaDoTheWorld/luaDoTheWorld")


local v = dtw.load_file("teste.jpg")

local i = 1 
while true  do
    
    local current = v[i]
    i = i+1
    if current == nil then
        break
    end

end