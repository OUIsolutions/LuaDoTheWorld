--local dtw = require("luaDoTheWorld/luaDoTheWorld")


local function teste(v)
    if v== nil then 
    error({teste=30,valor='aaaaa'})
    end 
    return "normal"
end 

local valor ,erro = pcall(teste)
print(valor)
print(erro)