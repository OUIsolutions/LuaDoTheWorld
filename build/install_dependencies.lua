function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = 'bc117dbac0e288e3511860e4036f5f77503997439bb6ded2427b6d3a25a3aee3'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end
    
    darwin.dtw.remove_any("dependencies")
    os.execute("mkdir -p dependencies")


    os.execute("curl -L https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.11.0/LuaCEmbedOne.c -o dependencies/LuaCEmbedOne.c")
    os.execute("curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/11.0.0/doTheWorldOne.c -o dependencies/doTheWorldOne.c")


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end