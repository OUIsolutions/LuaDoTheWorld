# 🧩 IO Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-IO-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for file and folder operations with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to load and write files
- ✅ How to copy and move files or folders (overwrite or merge)

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 📂 Load a File

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local content = dtw.load_file("tests/target/a.txt")
print(content)
```

---

## 📝 Write a File

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
dtw.write_file("tests/target/b.txt", "text content")
```

---

## 📋 Copy Anything (Overwrite)

This will copy a file or folder, overwriting whatever is at the destination.

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
dtw.copy_any_overwriting("tests/target/test_dir", "tests/target/a")
```

---

## 🔀 Copy Anything (Merge)

This will copy and merge folders if the destination is a folder.

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
dtw.copy_any_merging("tests/target/test_dir", "tests/target/a")
```

---

## 🚚 Move Anything (Overwrite)

This will move a file or folder, removing the destination if it exists.

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
dtw.move_any_overwriting("tests/target/test_dir", "tests/target/a")
```

---

## 🔄 Move Anything (Merge)

This will move and merge folders if the destination is a folder.

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
dtw.move_any_merging("tests/target/test_dir", "tests/target/a")
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.load_file(path)` | Load file content | `dtw.load_file("a.txt")` |
| `dtw.write_file(path, data)` | Write content to file | `dtw.write_file("b.txt", "text")` |
| `dtw.copy_any_overwriting(src, dest)` | Copy and overwrite | `dtw.copy_any_overwriting("dir", "a")` |
| `dtw.copy_any_merging(src, dest)` | Copy and merge | `dtw.copy_any_merging("dir", "a")` |
| `dtw.move_any_overwriting(src, dest)` | Move and overwrite | `dtw.move_any_overwriting("dir", "a")` |
| `dtw.move_any_merging(src, dest)` | Move and merge | `dtw.move_any_merging("dir", "a")` |

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)
