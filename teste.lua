


local dtw = require("luaDoTheWorld/luaDoTheWorld")

 local r  = dtw.newResource("clib")

 i = 1 
 while true  do 
    v = r[i]
    if v == nil then
        break
    end
    print(v)
    i = i+1
    
end 
