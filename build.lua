

local function main()

    print("compiling")

    os.execute("gcc -Wall -shared -fpic -o luaDoTheWorld/luaDoTheWorld_clib.so  clib/one.c")

end


main()