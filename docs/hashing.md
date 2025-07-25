

### Hashing
You can generate assignature of anything you want  with all the hash functions

#### Generating Sha from string
Will generate a sha256 assignature of a string

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha("what ever you want")
print(sha)
~~~

#### Generating Sha from file
Will generate a sha256 assignature of a file

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_file("tests/target/blob.png")
print(sha)
~~~

#### Generating Sha from folder by content
Will generate a sha256 assignature of a folder based on content

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_folder_by_content("tests/target/test_dir")
print(sha)
~~~


#### Generating Sha from folder by last modification
Will generate a sha256 assignature of a folder based on last modification

~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local sha = dtw.generate_sha_from_folder_by_last_modification("tests/target/test_dir")
print(sha)
~~~

### Hasher
if you need to combine a lot of different entries, you can use the DtwHasher object


~~~lua

local dtw = require("luaDoTheWorld/luaDoTheWorld")

local hasher = dtw.newHasher()
hasher.digest_file("tests/target/blob.png")
hasher.digest("what ever you want")
hasher.digest_folder_by_content("tests/target/test_dir")
--will print the acumulated haher
print(hasher.get_value())
~~~