# 🧩 Hashing Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Hashing-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for hashing with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to create a SHA256 hash from a string
- ✅ How to create a SHA256 hash from a file
- ✅ How to create a SHA256 hash from a folder (by content or by last modification)
- ✅ How to use the Hasher object to combine hashes

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🔑 Hash a String

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local sha = dtw.generate_sha("hello world")
print(sha)
```

---

## 📄 Hash a File

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local sha = dtw.generate_sha_from_file("tests/target/blob.png")
print(sha)
```

---

## 📁 Hash a Folder by Content

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local sha = dtw.generate_sha_from_folder_by_content("tests/target/test_dir")
print(sha)
```

---

## 🕒 Hash a Folder by Last Modification

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local sha = dtw.generate_sha_from_folder_by_last_modification("tests/target/test_dir")
print(sha)
```

---

## 🔄 Hash a Lua Table or Variable

You can hash a Lua table or variable directly using `dtw.digest_var`. This is useful for generating a SHA256 hash from structured data (tables, arrays, etc.).

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local data = dtw.digest_var({name="Mateus", age=38, hobbies={"coding", "gaming"}})
print("data:", data) -- 13d17b23ccee37a92107f8357e980851c6b05fd6e0a7f9878dc384babc8858e4
```

---

## 🧩 Combine Hashes with Hasher

If you want to hash many things together, use the Hasher object:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local hasher = dtw.newHasher()
hasher.digest_file("tests/target/blob.png")
hasher.digest("hello world")
hasher.digest_folder_by_content("tests/target/test_dir")
print(hasher.get_value())
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.generate_sha(str)` | Hash a string | `dtw.generate_sha("hello")` |
| `dtw.generate_sha_from_file(path)` | Hash a file | `dtw.generate_sha_from_file("file.png")` |
| `dtw.generate_sha_from_folder_by_content(path)` | Hash folder by content | `dtw.generate_sha_from_folder_by_content("dir")` |
| `dtw.generate_sha_from_folder_by_last_modification(path)` | Hash folder by last modification | `dtw.generate_sha_from_folder_by_last_modification("dir")` |
| `dtw.digest_var(table)` | Hash a Lua table/variable | `dtw.digest_var({a=1, b=2})` |
| `dtw.newHasher()` | Create a hasher object | `dtw.newHasher()` |
| `hasher.digest(data)` | Add string to hasher | `hasher.digest("hello")` |
| `hasher.digest_file(path)` | Add file to hasher | `hasher.digest_file("file.png")` |
| `hasher.digest_folder_by_content(path)` | Add folder to hasher | `hasher.digest_folder_by_content("dir")` |
| `hasher.get_value()` | Get the final hash | `hasher.get_value()` |

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)