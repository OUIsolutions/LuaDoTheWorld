function build_local()
    darwin.dtw.copy_any_overwriting("extra/starter.lua","release/luaDoTheWorld/luaDoTheWorld.lua")
    os.execute("gcc src/one.c -shared  -fpic -o release/luaDoTheWorld/luaDoTheWorld.so")
end


darwin.add_recipe({
    name="local_build",
    description="local_build",
    require="no_dep_amalgamation_build",
    outs={"release/luaDoTheWorld.lua", "release/luaDoTheWorld.so"},
    inputs={"dependencies","extra","starter", "src", "darwinconf.lua"},
    callback= build_local
})