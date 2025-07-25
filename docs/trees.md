
# 🌳 Trees & Tree Parts Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Trees-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for managing files as a one-dimensional list with LuaDoTheWorld Trees

---

## 📋 What You'll Learn

- ✅ How to create trees and tree parts
- ✅ How to load existing directories as trees
- ✅ How to modify files using tree operations
- ✅ How to use map, count, and find operations
- ✅ Understanding hardware operators (write, modify, remove)

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🌱 Create a New Tree

Create files from scratch using tree parts:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree()
local a = tree.newTreePart_empty("tests/target/Tree/a.txt")
a.set_value("content of a")
a.hardware_write()

local b = tree.newTreePart_empty("tests/target/Tree/b.txt")
b.set_value("content of b")
b.hardware_write()

tree.commit()
```

---

## 📂 Load Existing Directory as Tree

Work with files that already exist:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")
-- Now you can work with all files in the directory
```

---

## ✏️ Modify All Files in a Tree

Change all `.txt` files to `.py` extension:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

tree.each(function(element)
    if element.path.get_extension() == "txt" then
        element.path.set_extension("py")
    end
    element.hardware_modify()
end)

tree.commit()
```

---

## 🗺️ Map Tree to Custom Objects

Extract file information into a custom list:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local result, size = tree.map(function(element)
    return {
        path = element.path.get_full_path(),
        content = element.get_value()
    }
end)

for i = 1, size do
    local current = result[i]
    print("========================")
    print("path:", current.path)
    print("content:", current.content)
end
```

---

## 🔍 Count Files by Condition

Count how many `.py` files exist:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local size = tree.count(function(element)
    if element.path.get_extension() == "py" then
        return true
    end
end)

print("Python files found:", size)
```

---

## 🔧 Hardware Operations

### 📝 Hardware Write
Creates new files, ignoring previous existence:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function(element)
    if element.path.get_name() == "a.txt" then
        return true
    end
end)

target.path.set_name("new_name.txt")
target.hardware_write()  -- Creates new file, keeps old one
tree.commit()
```

### 🔄 Hardware Modify
Renames/moves files, considering previous path:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function(element)
    if element.path.get_name() == "a.txt" then
        return true
    end
end)

target.path.set_name("new_name.txt")
target.hardware_modify()  -- Renames the file
tree.commit()
```

### 🗑️ Hardware Remove
Deletes the specified tree part:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local tree = dtw.newTree_from_hardware("tests/target/test_dir")

local target = tree.find(function(element)
    if element.path.get_name() == "a.txt" then
        return true
    end
end)

target.hardware_remove()  -- Deletes the file
tree.commit()
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.newTree()` | Create empty tree | `local tree = dtw.newTree()` |
| `dtw.newTree_from_hardware(path)` | Load directory as tree | `dtw.newTree_from_hardware("folder")` |
| `tree.newTreePart_empty(path)` | Create new file part | `tree.newTreePart_empty("file.txt")` |
| `tree.each(function)` | Iterate over all parts | `tree.each(function(element) ... end)` |
| `tree.map(function)` | Transform tree to list | `tree.map(function(element) ... end)` |
| `tree.count(function)` | Count matching parts | `tree.count(function(element) ... end)` |
| `tree.find(function)` | Find specific part | `tree.find(function(element) ... end)` |
| `element.hardware_write()` | Create/overwrite file | `element.hardware_write()` |
| `element.hardware_modify()` | Rename/move file | `element.hardware_modify()` |
| `element.hardware_remove()` | Delete file | `element.hardware_remove()` |
| `tree.commit()` | Apply all changes | `tree.commit()` |

---

## 💡 Key Concepts

- **Tree**: A collection of files managed as a single unit
- **Tree Part**: Individual file within a tree
- **Hardware Write**: Creates new files (ignores old ones)
- **Hardware Modify**: Renames/moves files (considers old paths)
- **Hardware Remove**: Deletes files
- **Commit**: Applies all pending changes to disk

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)
