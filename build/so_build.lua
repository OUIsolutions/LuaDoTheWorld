function so_build()
-- Create a new container machine
    local machine = darwin.ship.create_machine("debian:latest")
    -- Configure container runtime
    machine.provider = darwin.argv.get_flag_arg_by_index({ "provider"},1, "podman")
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
    os.execute("cd release && zip -r luaDoTheWorld.zip luaDoTheWorld")
end


darwin.add_recipe({
    name="so_build",
    description="so_build",
    require="local_build",
    outs={"release/luaDoTheWorld.zip"},
    inputs={"dependencies","extra","starter", "src", "darwinconf.lua"},
    callback= so_build
})