# 🧩 Base64 Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Base64-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for encoding and decoding Base64 with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to encode a file to Base64
- ✅ How to decode Base64 back to a file
- ✅ How to encode/decode strings and binaries

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🔤 Encode a File to Base64

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local b64 = dtw.base64_encode_file("tests/target/blob.png")
print(b64)
```

---

## 🔁 Decode Base64 to File

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local b64 = dtw.base64_encode_file("tests/target/blob.png")
local image = dtw.base64_decode(b64)
dtw.write_file("tests/target/blob2.png", image)
```

---

## 🔄 Encode a String or Binary

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")
local image = dtw.load_file("tests/target/blob.png")
local b64 = dtw.base64_encode(image)
print(b64)
```

---

## 📚 Quick Reference

| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.base64_encode_file(path)` | Encode file to Base64 | `dtw.base64_encode_file("file.png")` |
| `dtw.base64_encode(data)` | Encode string/binary | `dtw.base64_encode(image)` |
| `dtw.base64_decode(b64)` | Decode Base64 to binary | `dtw.base64_decode(b64)` |
| `dtw.write_file(path, data)` | Write binary to file | `dtw.write_file("out.png", data)` |

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)
