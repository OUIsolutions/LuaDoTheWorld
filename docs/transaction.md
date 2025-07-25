
# 🔄 Transaction Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Transaction-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for atomic file operations with LuaDoTheWorld Transactions

---

## 📋 What You'll Learn

- ✅ How to create and execute atomic file operations
- ✅ How to save transactions to JSON for later use
- ✅ How to load and inspect transactions from JSON files
- ✅ How to prevent data corruption with atomic operations

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🔐 What Are Transactions?

Transactions are a way to perform multiple file operations **atomically** - meaning either all operations succeed, or none of them do. This prevents your data from being left in a broken state if something goes wrong!

---

## ✨ Create and Execute a Basic Transaction

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Create a new transaction
local transaction = dtw.newTransaction()

-- Add operations to the transaction
transaction.write("tests/target/a.txt", "content of a")
transaction.remove_any("tests/target/test_dir")
transaction.copy_any("tests/target/a", "tests/target/b")

-- Execute all operations atomically
transaction.commit()
```

---

## 💾 Save Transaction to JSON

Want to save your transaction for later? Export it to JSON!

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Create and configure transaction
local transaction = dtw.newTransaction()
transaction.write("tests/target/a.txt", "content of a")
transaction.remove_any("tests/target/test_dir")
transaction.copy_any("tests/target/a", "tests/target/b")

-- Export to JSON string
local transaction_json = transaction.dump_to_json_string()
print(transaction_json)
```

---

## 📂 Load Transaction from JSON File

Load a previously saved transaction and inspect its actions:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Load transaction from JSON file
local transaction = dtw.new_transaction_from_file("tests/target/json_transaction.json")

-- Inspect each action in the transaction
transaction.each(function(action)
    local dest = action.get_dest()
    local type = action.get_type()
    local source = action.get_source()
    local content = action.get_content()
    
    print("===================================")
    print("Destination:", dest)
    print("Source:", source)
    print("Operation Type:", type)
    print("Content:", content)
end)
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.newTransaction()` | Create new transaction | `local tx = dtw.newTransaction()` |
| `transaction.write(path, content)` | Add write operation | `tx.write("file.txt", "content")` |
| `transaction.copy_any(from, to)` | Add copy operation | `tx.copy_any("src", "dest")` |
| `transaction.remove_any(path)` | Add remove operation | `tx.remove_any("file.txt")` |
| `transaction.commit()` | Execute all operations | `tx.commit()` |
| `transaction.dump_to_json_string()` | Export to JSON | `local json = tx.dump_to_json_string()` |
| `dtw.new_transaction_from_file(path)` | Load from JSON file | `local tx = dtw.new_transaction_from_file("tx.json")` |

---

## 🎯 Common Use Cases

### 🔄 **Batch File Operations**
Perfect for moving, copying, and modifying multiple files safely.

### 💾 **Backup Scripts**
Create atomic backup operations that won't leave partial backups.

### 🔧 **Configuration Management**
Update multiple config files atomically to prevent inconsistent states.

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)

