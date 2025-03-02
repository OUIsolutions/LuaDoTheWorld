function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = '14133ed1907c9c4a058f04af0066d4dd0f9e50ea12365e640298e9752add7a2b'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end
    
    darwin.dtw.remove_any("dependencies")
    os.execute("mkdir -p dependencies")

    
    os.execute("curl -L https://github.com/OUIsolutions/LuaCEmbed/releases/download/v0.780/LuaCEmbed.h -o dependencies/LuaCEmbed.h")
    os.execute("curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.002/doTheWorld.h -o dependencies/doTheWorld.h")


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end