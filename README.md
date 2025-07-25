# 🌍 LuaDoTheWorld

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![Platform](https://img.shields.io/badge/Platform-Linux-orange?style=flat-square&logo=linux)
![Version](https://img.shields.io/badge/Version-0.7.0-green?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-purple?style=flat-square)

> 🚀 **The ultimate Lua library for file and folder operations** - From simple read/write to advanced transactions and hashing!

---

## ✨ What Can You Do?

LuaDoTheWorld makes file operations **incredibly simple**! Whether you're a beginner or an expert, you can:

- 📂 **Read, write, copy, and move** files and folders
- 🔍 **List directories** recursively or non-recursively  
- 🔒 **Hash files and folders** with SHA256
- 🔐 **Lock files** for safe concurrent access
- 🌳 **Manage file trees** like databases
- 🔄 **Create atomic transactions** for safe operations
- 🛤️ **Manipulate file paths** easily
- 📁 **Handle resources** like smart dictionaries

---

## 🚀 Quick Start

### 1️⃣ Install LuaDoTheWorld

Download and extract in your project:

```bash
curl -L -o luaDoTheWorld.zip https://github.com/OUIsolutions/LuaDoTheWorld/releases/download/0.7.0/luaDoTheWorld.zip && unzip luaDoTheWorld.zip && rm luaDoTheWorld.zip
```

### 2️⃣ Use in Your Code

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Write a file
dtw.write_file("hello.txt", "Hello, World!")

-- Read a file
local content = dtw.load_file("hello.txt")
print(content) -- Hello, World!

-- Copy anything
dtw.copy_any_overwriting("hello.txt", "backup.txt")
```

**That's it!** 🎉 You're ready to manipulate files like a pro!

---

## 📚 Complete Documentation

### 🎯 **Core Operations**
| Guide | What You'll Learn | Difficulty |
|-------|------------------|------------|
| [📂 IO Operations](docs/io.md) | Read, write, copy, move files | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |
| [📋 Directory Listing](docs/listage.md) | List files and folders | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |
| [🛤️ Path Manipulation](docs/path.md) | Work with file paths | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |

### 🔒 **Security & Hashing**
| Guide | What You'll Learn | Difficulty |
|-------|------------------|------------|
| [🔑 Hashing](docs/hashing.md) | Generate SHA256 hashes | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |
| [🔒 File Locking](docs/locker.md) | Prevent file conflicts | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |
| [🔤 Base64 Encoding](docs/base_64.md) | Encode/decode Base64 | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |
| [🔄 Serialization](docs/serialization.md) | Serialize/deserialize Lua objects | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |

### 🚀 **Advanced Features**
| Guide | What You'll Learn | Difficulty |
|-------|------------------|------------|
| [📁 Resource Management](docs/resource.md) | File-as-database operations | ![Intermediate](https://img.shields.io/badge/Difficulty-Intermediate-yellow?style=flat-square) |
| [🔄 Transactions](docs/transaction.md) | Atomic file operations | ![Intermediate](https://img.shields.io/badge/Difficulty-Intermediate-yellow?style=flat-square) |
| [🌳 Tree Operations](docs/trees.md) | Manage files as trees | ![Intermediate](https://img.shields.io/badge/Difficulty-Intermediate-yellow?style=flat-square) |
| [🍴 Process Forking](docs/fork.md) | Multi-process operations | ![Advanced](https://img.shields.io/badge/Difficulty-Advanced-red?style=flat-square) |

### 🛠️ **Utilities**
| Guide | What You'll Learn | Difficulty |
|-------|------------------|------------|
| [💾 Cache System](docs/cache.md) | Intelligent function caching | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |
| [🕒 Modification Time](docs/modification_status.md) | Check file timestamps | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |
| [🛠️ Build from Scratch](docs/build_from_scratch.md) | Compile the library | ![Beginner](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square) |

---

## 💡 Quick Examples

### Copy Files Safely
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
dtw.copy_any_merging("source_folder", "backup_folder")
```

### Generate File Hash
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local hash = dtw.generate_sha_from_file("important.txt")
print("File hash:", hash)
```

### List All Files Recursively
```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local files, count = dtw.list_files_recursively("my_project", false)
for i = 1, count do
    print("Found:", files[i])
end
```

---

## ⚠️ Important Notes

- 🐧 **Linux Only**: Currently supports Linux systems
- 🌙 **Lua 5.4+**: Requires Lua version 5.4 or higher  
- 🧪 **Development**: Library is in active development

---

## 🆘 Need Help?

- 📖 **Read the guides** above for step-by-step tutorials
- 🔍 **Check the examples** folder for real code samples
- 🐛 **Report issues** on our GitHub repository
- 💬 **Ask questions** in our community

---

## 🙏 Credits

LuaDoTheWorld is a Lua wrapper for the original [DoTheWorld](https://github.com/OUIsolutions/DoTheWorld) C library.

---

<div align="center">

![Happy Coding](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)

**Made with ❤️ for the Lua community**

</div>

