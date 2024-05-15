
local dtw = require("luaDoTheWorld/luaDoTheWorld")



local banco = dtw.newResource("banco")
local usuarios = banco.sub_schema("usuarios")
usuarios.add_primary_keys("nome")
usuarios.add_primary_keys("email")


local testagem = usuarios.map(function(r)
    return  {
        nome=tostring(r.sub_resource("nome"))
    }
end)

for i,v in ipairs(testagem) do
    print(v.nome)
end


