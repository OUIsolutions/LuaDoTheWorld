
-- means its linux
if os.getenv("HOME") then
    os.execute("gcc -Wall -shared -fpic -o luaDoTheWorld/linuxlib.so  clib/main.c")
end 
--means its windows
if  package.config:sub(1,1) == '\\' then
    print("Sistema Windows")
end


