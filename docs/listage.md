# 🧩 Listage Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Listage-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for listing files and directories with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to list files in a directory
- ✅ How to list directories
- ✅ How to list everything (files + dirs)
- ✅ How to list recursively

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 📂 List Files in a Directory

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local concat_path = false -- set to true to include full paths
local files, size = dtw.list_files("tests/target/test_dir", concat_path)

for i = 1, size do
    print(files[i])
end
```

---

## 📁 List Directories in a Directory

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local concat_path = false
local dirs, size = dtw.list_dirs("tests/target/test_dir", concat_path)

for i = 1, size do
    print(dirs[i])
end
```

---

## 🗂️ List All (Files + Dirs)

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local concat_path = false
local elements, size = dtw.list_all("tests/target/test_dir", concat_path)

for i = 1, size do
    print(elements[i])
end
```

---

## 🔄 List Files Recursively

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local concat_path = false
local files, size = dtw.list_files_recursively("tests/target/test_dir", concat_path)

for i = 1, size do
    print(files[i])
end
```

---

## 🔁 List Dirs Recursively

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local concat_path = false
local dirs, size = dtw.list_dirs_recursively("tests/target/test_dir", concat_path)

for i = 1, size do
    print(dirs[i])
end
```

---

## 🌀 List All Recursively (Files + Dirs)

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local concat_path = false
local elements, size = dtw.list_all_recursively("tests/target/test_dir", concat_path)

for i = 1, size do
    print(elements[i])
end
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.list_files(path, concat)` | List files in dir | `dtw.list_files("dir", false)` |
| `dtw.list_dirs(path, concat)` | List dirs in dir | `dtw.list_dirs("dir", false)` |
| `dtw.list_all(path, concat)` | List files + dirs | `dtw.list_all("dir", false)` |
| `dtw.list_files_recursively(path, concat)` | List files recursively | `dtw.list_files_recursively("dir", false)` |
| `dtw.list_dirs_recursively(path, concat)` | List dirs recursively | `dtw.list_dirs_recursively("dir", false)` |
| `dtw.list_all_recursively(path, concat)` | List all recursively | `dtw.list_all_recursively("dir", false)` |

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)