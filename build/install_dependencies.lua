function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = 'e046c433300bac4f5d7ff7ea5e105cf23ebba9abb0394357f50cf7def0ef98a4'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end
    
    darwin.dtw.remove_any("dependencies")
    os.execute("mkdir -p dependencies")


    os.execute("curl -L https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.11.0/LuaCEmbedOne.c -o dependencies/LuaCEmbedOne.c")
    os.execute("curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.002/doTheWorld.h -o dependencies/doTheWorld.h")


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end