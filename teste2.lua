local dtw = require("luaDoTheWorld/luaDoTheWorld")



local banco = dtw.newResource("banco")
local usuarios = banco.sub_schema("usuarios")
usuarios.add_primary_keys("nome")
usuarios.add_primary_keys("email")


local possivel_usuario = usuarios.get_resource_matching_primary_key("nome","mateus")


print(possivel_usuario.sub_resource("nome"))

--local mateus = usuarios.new_insertion()
--mateus.set_value_in_sub_resource("nome","mateus")
--mateus.set_value_in_sub_resource("idade",27)
--mateus.set_value_in_sub_resource("email","mateusmoutinho01@gmail.com")


banco.commit()



