
function main()
    darwin.dtw.remove_any("release")

    install_dependencies()


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

    local builded = false
    if darwin.argv.one_of_args_exist("build_local") then
        darwin.dtw.copy_any_overwriting("extra/starter.lua","release/luaDoTheWorld/luaDoTheWorld.lua")
        os.execute("gcc src/one.c -shared  -fpic -o release/luaDoTheWorld/luaDoTheWorld.so")
        builded = true
    end

    if darwin.argv.one_of_args_exist("build_release") then
        darwin.dtw.copy_any_overwriting("extra/starter.lua","release/luaDoTheWorld/luaDoTheWorld.lua")

        -- Create a new container machine
        local machine = darwin.ship.create_machine("debian:latest")
        -- Configure container runtime
        machine.provider = darwin.argv.get_flag_arg_by_index({ "provider"},1, "docker")
        -- Add build-time commands
        machine.add_comptime_command("apt update")
        machine.add_comptime_command("apt install -y gcc")
        
        machine.start({
            flags = {
                "--network=host"
            },
            volumes = {
                { ".", "/output" }
            },
            command = "gcc -shared -fpic /output/src/one.c -o /output/release/luaDoTheWorld/luaDoTheWorld.so"
        })

        builded = true
    end
    
    if builded then
        os.execute("cd release && zip -r luaDoTheWorld.zip luaDoTheWorld")
    end
end