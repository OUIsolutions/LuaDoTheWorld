
function main()
    install_dependencies()

    darwin.silverchain.generate({
        src = "src",
        project_shortcut="luaDoTheWorld",
        tags = { "dependencie", "consts", "macros", "globals", "fdeclare", "fdefine" },
        implement_main = false
    })


end