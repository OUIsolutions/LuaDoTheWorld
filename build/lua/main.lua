



local function main()

        local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
        local cache = NewCache(CACHE_POINT)

        local status =clib.system_with_status("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  src/one.c -DDTW_DEBUG_TIME")
        if status ~= 0 then
            clib.print(ANSI_RED.."impossible to compile")
        	clib.exit(1)
        end
        Execute_full_test(cache,src_sha)

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

end

main()