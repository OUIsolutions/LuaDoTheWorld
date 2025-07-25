# 🔒 Locker Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Locker-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for file locking and process concurrency with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to lock and unlock files
- ✅ How to manage concurrency between processes
- ✅ How to use lockers in forked processes

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🔒 Lock and Unlock a File

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local locker = dtw.newLocker()
locker.lock("a.txt")
-- Do something with the locked file
locker.unlock("a.txt")
```

---

## 🤖 Locking in Multiple Processes (Fork Example)

Create 30 forks, each writing its number to a file safely using a locker:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local all_forks = {}
local total_forks = 30

dtw.remove_any("a.txt")

for i = 1, total_forks do
    local fork = dtw.newFork(function()
        local locker = dtw.newLocker()
        locker.lock("a.txt")
        local old = dtw.load_file("a.txt")
        if old == nil then old = "" end
        old = old .. i .. "\n"
        dtw.write_file("a.txt", old)
        locker.unlock("a.txt")
    end)
    all_forks[i] = fork
end

-- Wait for all child processes to finish
for i = 1, total_forks do
    all_forks[i].wait(-1)
end
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.newLocker()` | Create a new locker | `local locker = dtw.newLocker()` |
| `locker.lock(path)` | Lock a file | `locker.lock("a.txt")` |
| `locker.unlock(path)` | Unlock a file | `locker.unlock("a.txt")` |
| `dtw.newFork(fn)` | Create a new process | `dtw.newFork(function() ... end)` |

---

## 📝 Notes

- Lockers prevent file access conflicts **between processes** (not threads).
- Only works if all processes use LuaDoTheWorld's locker system.

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)