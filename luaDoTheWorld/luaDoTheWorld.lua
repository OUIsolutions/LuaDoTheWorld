
-- means its linux
if os.getenv("HOME") then
    return require("linuxlib")
--means its windows
if  package.config:sub(1,1) == '\\' then
    print("Sistema Windows")
end
