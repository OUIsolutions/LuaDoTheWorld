



local function main()

        local cache = NewCache(CACHE_POINT)

        local status =clib.system_with_status("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  src/one.c -DDTW_DEBUG_TIME")
        if status ~= 0 then
            clib.print(ANSI_RED.."impossible to compile")
        	clib.exit(1)
        end

        local dll_sha = dtw.generate_sha_from_file("luaDoTheWorld/luaDoTheWorld_clib.so")

        Execute_full_test(cache,dll_sha)

        Create_examples()

        clib.print(ANSI_RESET)

        local final_status =clib.system_with_status("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  src/one.c")
        if final_status ~= 0 then
            clib.print(ANSI_RED.."impossible to compile")
        	clib.exit(1)
        end

        local readme = Create_readme()
        if readme ~= nil then
            dtw.write_file("README.md",readme)
        end
        clib.system_with_status("")

end

main()