# 🕒 Modification Status Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Modification_Status-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for checking file and folder modification times with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to get the last modification time of a file or folder
- ✅ How to get the modification time in Unix timestamp format

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🗂️ Get Last Modification Time (Human-Readable)

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local last = dtw.get_entity_last_modification("tests/target/blob.png")
print(last)  -- Example output: "2025-07-24 15:30:12"
```

---

## 🕑 Get Last Modification Time (Unix Timestamp)

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local last_in_unix = dtw.get_entity_last_modification_in_unix("tests/target/blob.png")
print(last_in_unix)  -- Example output: 1750000000
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.get_entity_last_modification(path)` | Get last modification (readable) | `dtw.get_entity_last_modification("file.txt")` |
| `dtw.get_entity_last_modification_in_unix(path)` | Get last modification (Unix) | `dtw.get_entity_last_modification_in_unix("file.txt")` |

---

## 📝 Notes

- Works for both files and folders.
- Useful for backups, syncing, or monitoring changes.

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)