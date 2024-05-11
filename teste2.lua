






local dtw = require("luaDoTheWorld/luaDoTheWorld")

local resources = dtw.newResource("clib")
resources.foreach(function (element)
    print(element.get_path())
end)
