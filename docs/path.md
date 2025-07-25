# 🛤️ Path Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Path-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for handling file paths with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to extract file name, directory, and extension
- ✅ How to get subdirectories from a path
- ✅ How to change directory, name, or extension
- ✅ How to insert or replace directories in a path

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🏷️ Basic Path Extraction

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
print("name", path.get_name())        -- c.txt
print("dir", path.get_dir())          -- a/b
print("extension", path.get_extension()) -- txt
```

---

## 📂 Extracting Subdirectories

You can extract subdirectories by index. Use negative numbers for counting from the end (-1 is last, -2 is second last).

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
local sub_dirs = path.get_sub_dirs_from_index(1, -1)
print(sub_dirs) -- b
```

---

## ✏️ Changing Path Parts

### Set Directory

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
path.set_dir("test")
print(path.get_full_path()) -- test/c.txt
```

### Set Name

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
path.set_name("d.txt")
print(path.get_full_path()) -- a/b/d.txt
```

### Set Extension

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
path.set_extension("py")
print(path.get_full_path()) -- a/b/c.py
```

---

## ➕ Inserting Directories

### Insert After Directory

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
path.insert_dir_after("a", "inserted_dir")
print(path.get_full_path()) -- a/inserted_dir/b/c.txt
```

### Insert Before Directory

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
path.insert_dir_before("a", "inserted_dir")
print(path.get_full_path()) -- inserted_dir/a/b/c.txt
```

### Insert at Index

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
path.insert_dir_at_index(1, "inserted_dir")
print(path.get_full_path()) -- a/inserted_dir/b/c.txt
```

---

## 🔄 Replacing Directories

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local path = dtw.newPath("a/b/c.txt")
path.replace_dirs("a", "inserted_dir")
print(path.get_full_path()) -- inserted_dir/b/c.txt
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.newPath(path)` | Create a new path object | `dtw.newPath("a/b/c.txt")` |
| `path.get_name()` | Get file name | `path.get_name()` |
| `path.get_dir()` | Get directory | `path.get_dir()` |
| `path.get_extension()` | Get extension | `path.get_extension()` |
| `path.get_sub_dirs_from_index(start, end)` | Get subdirectories | `path.get_sub_dirs_from_index(1, -1)` |
| `path.set_dir(dir)` | Set directory | `path.set_dir("test")` |
| `path.set_name(name)` | Set file name | `path.set_name("d.txt")` |
| `path.set_extension(ext)` | Set extension | `path.set_extension("py")` |
| `path.insert_dir_after(target, dir)` | Insert dir after | `path.insert_dir_after("a", "inserted_dir")` |
| `path.insert_dir_before(target, dir)` | Insert dir before | `path.insert_dir_before("a", "inserted_dir")` |
| `path.insert_dir_at_index(idx, dir)` | Insert dir at index | `path.insert_dir_at_index(1, "inserted_dir")` |
| `path.replace_dirs(target, dir)` | Replace dir | `path.replace_dirs("a", "inserted_dir")` |

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)

