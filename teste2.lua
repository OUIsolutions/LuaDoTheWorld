local dtw = require("luaDoTheWorld/luaDoTheWorld")



local banco = dtw.newResource("banco")
local usuarios = banco.sub_schema("usuarios")
usuarios.add_primary_keys("nome")
usuarios.add_primary_keys("email")


local possivel_usuario = usuarios.find(function(r)
    return  tostring(r.sub_resource("nome")) == 'mateus'
end)

print(possivel_usuario.sub_resource("email"))
