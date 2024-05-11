






local dtw = require("luaDoTheWorld/luaDoTheWorld")

local elements = dtw.newResource("clib")

elements.foreach(function (t)
    print(t.get_path())
end)
