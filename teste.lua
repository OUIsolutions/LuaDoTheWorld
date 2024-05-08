






local dtw = require("luaDoTheWorld/luaDoTheWorld")
local banco = dtw.newResource("banco")
function encontra_ususario (nome)
    local todos_usuarios = banco.sub_resource("usuarios")
    local index = 1
    while true do
    local possivel_usuario = todos_usuarios.sub_resource (index)   
    local possive_nome = possivel_usuario.sub_resource ("nome")
        print(possivel_nome)
    end 
end
encontra_ususario ("Mateus")