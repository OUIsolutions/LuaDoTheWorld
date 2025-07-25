# 🧩 Fork Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Fork-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for using Forks with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to run code in a new process (fork)
- ✅ How to wait for a fork to finish
- ✅ How to stop a forked process

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script
- Unix-like environment (Linux, macOS) for process management

---

## 🍴 Fork a Process

Run code in a new process (fork):

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local fork = dtw.newFork(function()
    print("executed inside fork")
end)

local one_second = 1000 -- milliseconds
fork.wait(one_second)

print("executed in main process")
```

---

## ⏹️ Stop a Forked Process

You can stop (kill) a fork if it is still running:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local fork = dtw.newFork(function()
    while true do
        print("executed inside fork")
    end
end)

local half_second = 500 -- milliseconds
fork.wait(half_second)
if fork.is_alive() then
    fork.kill()
end

print("executed in main process")
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.newFork(func)` | Create a new forked process | `dtw.newFork(function() ... end)` |
| `fork.wait(ms)` | Wait for fork to finish (ms) | `fork.wait(1000)` |
| `fork.is_alive()` | Check if fork is running | `fork.is_alive()` |
| `fork.kill()` | Stop the forked process | `fork.kill()` |

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)