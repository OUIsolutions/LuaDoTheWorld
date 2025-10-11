
function no_dep_amalgamation_build()
    darwin.silverchain.generate({
        src = "src",
        project_short_cut="luaDoTheWorld",
        tags = { "dependencie", "consts", "macros","type", "globals", "fdeclare", "fdefine" },
        implement_main = false
    })

    local no_dep_amalgamation = darwin.camalgamator.generate_amalgamation_with_callback("src/one.c",
        function(import, path)
            if import == "src/imports/../dependencie.dependencies.h"  then
                return "dont-include"
            end
            return "include-once"
            
        end,
        MAX_CONNTENT,
        MAX_RECURSION
    )
    darwin.dtw.write_file("release/luaDoTheWorld_no_dep.c", no_dep_amalgamation)
end


darwin.add_recipe({
    name="no_dep_amalgamation_build",
    description="no_dep_amalgamation_build",
    outs={"release/luaDoTheWorld_no_dep.lua"},
    inputs={"dependencies","extra","starter", "src", "darwinconf.lua"},
    callback=no_dep_amalgamation_build
})
