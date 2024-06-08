



local function main()

        local src_sha = Generate_sha_from_folder_not_considering_empty_folders(LIB_FOLDER)
        local cache = NewCache(CACHE_POINT)


        Execute_full_test(cache,src_sha)

        Create_examples()
        dtw.write_file("exemples/locker/locker_test.c",locker_content)

        clib.print(ANSI_RESET)


        local readme = Create_readme()
        if readme ~= nil then
            dtw.write_file("README.md",readme)
        end

        dtw.write_file(OUT_PUT_NAME,amalgamation_result)
end

main()