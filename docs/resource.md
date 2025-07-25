
# 📁 Resource Management Guide

![Lua](https://img.shields.io/badge/Language-Lua-blue?style=flat-square&logo=lua)
![API](https://img.shields.io/badge/API-Resources-green?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)
![Version](https://img.shields.io/badge/SDK-LuaDoTheWorld-orange?style=flat-square)

> 🚀 **Quick Start Guide** for managing files and folders like dictionaries with LuaDoTheWorld

---

## 📋 What You'll Learn

- ✅ How to create and manipulate file/folder resources
- ✅ How to work with sub-resources (files inside folders)
- ✅ How to use schemas for database-like operations
- ✅ How to list, filter, and search through resources

---

## 🛠️ Prerequisites

- LuaDoTheWorld installed and required in your script

---

## 🏗️ Create Your First Resource

Resources are like smart file/folder managers that automatically understand if you're working with files or folders.

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Create a resource (can be file or folder)
local myFolder = dtw.newResource("my_project")
local myFile = myFolder.sub_resource("config.txt")
myFile.set_value("Hello, World!")
myFolder.commit() -- Save changes to disk
```

---

## 📖 Read from Files

Get content from any file easily:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
local configFile = myFolder.sub_resource("config.txt")
print(configFile.get_value()) -- Prints file content
```

---

## 🔍 Get Values from Sub-Resources

Read files directly without creating sub-resource objects:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
print(myFolder.get_value_from_sub_resource("config.txt"))
```

---

## ✏️ Write to Files

Set content in files within folders:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
myFolder.set_value_in_sub_resource("config.txt", "New configuration data")
myFolder.commit() -- Don't forget to save!
```

---

## 🗑️ Delete Resources

Remove files or entire folders:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
local oldFile = myFolder.sub_resource("old_config.txt")
oldFile.destroy() -- Mark for deletion
myFolder.commit() -- Apply deletion
```

---

## 📋 List All Files and Folders

See what's inside a folder:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
local elements, size = myFolder.list()

for i = 1, size do
    local item = elements[i]
    print("Path:", item.get_path_string())
    print("Type:", item.get_type()) -- "file" or "folder"
end
```

---

## 🔄 Loop Through Resources (Each)

Process each file/folder with a function:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
myFolder.each(function(item)
    print("Found:", item.get_path_string())
    print("Type:", item.get_type())
end)
```

---

## 🗺️ Transform Resources (Map)

Create a new structure from your resources:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
local fileInfo, size = myFolder.map(function(item)
    return {
        path = item.get_path_string(),
        content = item.get_value(),
        type = item.get_type()
    }
end)

for i = 1, size do
    local info = fileInfo[i]
    print("Path:", info.path)
    print("Content:", info.content)
    print("Type:", info.type)
end
```

---

## 🔍 Find Specific Resources

Search for files by name or other criteria:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
local targetFile = myFolder.find(function(item)
    local path = dtw.newPath(item.get_path_string())
    return path.get_name() == "config.txt"
end)

if targetFile then
    print("Found:", targetFile.get_value())
end
```

---

## 🔎 Filter Resources

Get only files that match your criteria:

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local myFolder = dtw.newResource("my_project")
local textFiles, size = myFolder.filter(function(item)
    local path = dtw.newPath(item.get_path_string())
    return path.get_extension() == ".txt"
end)

for i = 1, size do
    local file = textFiles[i]
    print("Text file:", file.get_path_string())
end
```

---

## 🕒 Auto-Generated Resource Names

### Current Time Filename

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local logs = dtw.newResource("logs")
local logFile = logs.sub_resource_now(".log") -- Creates "2024-01-15_14-30-25.log"
logFile.set_value("Application started")
logs.commit()
```

### Unix Timestamp Filename

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local backups = dtw.newResource("backups")
local backup = backups.sub_resource_now_in_unix(".backup") -- Creates "1705320625.backup"
backup.set_value("Backup data")
backups.commit()
```

### Random Filename

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local temp = dtw.newResource("temp")
local tempFile = temp.sub_resource_random(".tmp") -- Creates random name like "a7b9c2d4.tmp"
tempFile.set_value("Temporary data")
temp.commit()
```

### Sequential Filename

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local uploads = dtw.newResource("uploads")
local nextFile = uploads.sub_resource_next(".jpg") -- Creates "1.jpg", "2.jpg", etc.
nextFile.set_value("Image data")
uploads.commit()
```

---

## 🗄️ Database-Like Operations (Schemas)

Turn your folders into databases with primary keys and queries!

### Create a User Database

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

-- Setup database structure
local database = dtw.newResource("user_database")
local schema = database.newDatabaseSchema()
local users = schema.sub_schema("users")
users.add_primary_keys({"name", "email"}) -- Prevent duplicates

-- Create a user
local userTable = users.schema_new_insertion()
userTable.set_value_in_sub_resource("name", "John Doe")
userTable.set_value_in_sub_resource("email", "john@example.com")
userTable.set_value_in_sub_resource("password", "secret123")

database.commit()
```

### Find User by Email

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local database = dtw.newResource("user_database")
local users = database.sub_resource("users")

-- Find user by primary key
local user = users.get_resource_matching_primary_key("email", "john@example.com")
if user then
    print("Name:", user.get_value_from_sub_resource("name"))
    print("Email:", user.get_value_from_sub_resource("email"))
else
    print("User not found")
end
```

### List All Users

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local database = dtw.newResource("user_database")
local users = database.sub_resource("users")

local allUsers, count = users.schema_list()
for i = 1, count do
    local user = allUsers[i]
    print("User:", user.get_value_from_sub_resource("name"))
    print("Email:", user.get_value_from_sub_resource("email"))
end
```

### Filter Users by Age

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local database = dtw.newResource("user_database")
local users = database.sub_resource("users")

local adults, count = users.schema_filter(function(user)
    local age = user.get_value_from_sub_resource("age")
    return age and age >= 18
end)

for i = 1, count do
    local user = adults[i]
    print("Adult user:", user.get_value_from_sub_resource("name"))
end
```

### Delete a User

```lua
local dtw = require("luaDoTheWorld/luaDoTheWorld")

local database = dtw.newResource("user_database")
local users = database.sub_resource("users")

local user = users.get_resource_matching_primary_key("email", "john@example.com")
if user then
    user.destroy() -- Safely removes user and all their data
    print("User deleted")
end

database.commit()
```

---

## 📚 Quick Reference

### Basic Operations
| Function | What it does | Example |
|----------|--------------|---------|
| `dtw.newResource(path)` | Create resource | `dtw.newResource("my_folder")` |
| `resource.sub_resource(name)` | Get sub-resource | `folder.sub_resource("file.txt")` |
| `resource.set_value(data)` | Write to file | `file.set_value("Hello")` |
| `resource.get_value()` | Read from file | `file.get_value()` |
| `resource.commit()` | Save changes | `folder.commit()` |
| `resource.destroy()` | Delete resource | `file.destroy()` |

### Listing and Searching
| Function | What it does | Example |
|----------|--------------|---------|
| `resource.list()` | List all items | `folder.list()` |
| `resource.each(func)` | Loop through items | `folder.each(function(item) ... end)` |
| `resource.map(func)` | Transform items | `folder.map(function(item) ... end)` |
| `resource.find(func)` | Find first match | `folder.find(function(item) ... end)` |
| `resource.filter(func)` | Filter items | `folder.filter(function(item) ... end)` |

### Auto-Generated Names
| Function | What it does | Example |
|----------|--------------|---------|
| `resource.sub_resource_now(ext)` | Time-based name | `folder.sub_resource_now(".log")` |
| `resource.sub_resource_now_in_unix(ext)` | Unix timestamp | `folder.sub_resource_now_in_unix(".bak")` |
| `resource.sub_resource_random(ext)` | Random name | `folder.sub_resource_random(".tmp")` |
| `resource.sub_resource_next(ext)` | Sequential number | `folder.sub_resource_next(".jpg")` |

### Schema (Database) Operations
| Function | What it does | Example |
|----------|--------------|---------|
| `resource.newDatabaseSchema()` | Create schema | `db.newDatabaseSchema()` |
| `schema.sub_schema(name)` | Create table | `schema.sub_schema("users")` |
| `schema.add_primary_keys(keys)` | Set unique fields | `users.add_primary_keys({"email"})` |
| `schema.schema_new_insertion()` | Create record | `users.schema_new_insertion()` |
| `schema.get_resource_matching_primary_key(key, value)` | Find by key | `users.get_resource_matching_primary_key("email", "john@example.com")` |
| `schema.schema_list()` | List all records | `users.schema_list()` |
| `schema.schema_filter(func)` | Filter records | `users.schema_filter(function(user) ... end)` |

---

## 🆘 Need Help?

- 📖 Check the main SDK documentation
- 🔍 Look at other example scripts in the SDK
- 🐛 Report issues on our GitHub repository

---

![Footer](https://img.shields.io/badge/Happy-Coding!-ff69b4?style=flat-square&logo=heart)

