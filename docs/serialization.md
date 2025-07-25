# 🔄 Serialization Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Serialization-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for serializing and deserializing Lua variables with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to serialize Lua tables to strings
- ✅ How to deserialize strings back to Lua objects
- ✅ How to save serialized data to files
- ✅ How to load serialized data from files

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 📦 Serialize a Lua Table

Convert any Lua table to a string that can be saved or transmitted:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local data_to_serialize = {
    name = "mateusÂããã",
    age = 30,
    hobbies = {"coding", "gaming"}
}

local serialized = dtw.serialize_var(data_to_serialize)
print(serialized)
-- Output: (function();return {['age'] = 30.000000, ['hobbies'] =  {'coding', 'gaming' }, ['name'] = 'mateus\195\130\195\163\195\163\195\163' };end)();
```

---

## 💾 Save Serialized Data to File

Store your serialized data in a file for later use:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local data = {
    name = "João",
    score = 95.5,
    items = {"sword", "shield", "potion"}
}

local serialized = dtw.serialize_var(data)
local formatted = "return " .. serialized
dtw.write_file("player_data.lua", formatted)
```

---

## 📖 Load Serialized Data from File

Retrieve your data back using Lua's require system:

```lua
-- Load using require (this also evaluates/executes the code)
local player_data = require("player_data")
print(player_data.name)  -- João
print(player_data.score) -- 95.5
```

---

## 🔄 Deserialize from String

Convert a serialized string back to a Lua object:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Get serialized data
local data = {level = 5, coins = 1000}
local serialized = dtw.serialize_var(data)

-- Deserialize back to object (evaluates the code!)
local restored_data = dtw.interpret_serialized_var(serialized)
print(restored_data.level) -- 5
print(restored_data.coins) -- 1000
```

---

## ⚠️ Safety Tips

- 🔒 **Both methods execute code** - `require()` and `interpret_serialized_var()` both evaluate Lua code
- 🛡️ **Only use with trusted data** - Never load serialized data from untrusted sources
- 💾 **Save as `.lua` files** - This allows you to use Lua's require system
- 🧹 **Add "return " prefix** - When saving to files for require compatibility
- 🔍 **Prefer `require()` for files** - It's the standard way to load Lua modules

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.serialize_var(table)` | Convert table to string | `dtw.serialize_var({a=1, b=2})` |
| `dtw.interpret_serialized_var(str)` | Evaluate string as Lua code | `dtw.interpret_serialized_var(serialized)` |
| `dtw.write_file(path, data)` | Save string to file | `dtw.write_file("data.lua", content)` |
| `require("filename")` | Load and evaluate .lua file | `require("data")` |

---

## 🎯 Complete Example

Here's a full workflow from serialization to loading:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- 1. Create some data
local game_state = {
    player = "Alice",
    level = 10,
    inventory = {"key", "map", "torch"},
    stats = {
        health = 100,
        mana = 50
    }
}

-- 2. Serialize the data
local serialized = dtw.serialize_var(game_state)

-- 3. Save to file (add "return " for require compatibility)
local formatted = "return " .. serialized
dtw.write_file("game_save.lua", formatted)

-- 4. Load the data back
local loaded_game = require("game_save")
print("Welcome back, " .. loaded_game.player .. "!")
print("You are at level " .. loaded_game.level)
```

---

## 🔍 What Gets Serialized?

✅ **Supported Types:**
- Numbers (integers and floats)
- Strings (including UTF-8)
- Tables (nested tables supported)
- Booleans

❌ **Not Supported:**
- Functions
- Userdata
- Threads
- Circular references

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)
