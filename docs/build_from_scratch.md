# 🛠️ Build From Scratch Guide

![Build](https://img.shields.io/badge/Action-Build-blue?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)

> 🚀 **Quick Start**: Build the project in just a few steps!

---

## 📋 What You Need

- [Darwin](https://github.com/OUIsolutions/Darwin) installed on your computer
- **Docker** or **Podman** installed (one of them is required)
- Access to your terminal

---

## 1️⃣ Install Darwin

Copy and run this command in your terminal:

```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.out -o darwin.out && chmod +x darwin.out &&  sudo  mv darwin.out /usr/bin/darwin
```

---

## 2️⃣ Build the Project

Go to the project folder and run:

```bash
darwin run_blueprint build/ --mode folder build_release
```

By default, **Docker** is used as the provider. If you want to use **Podman** instead, add the `--provider podman` option:

```bash
darwin run_blueprint build/ --mode folder build_release --provider podman
```

That's it! 🎉

---

## 🆘 Need Help?

- 📖 Check the main documentation
- 🐛 Report issues on our GitHub

![Footer](https://img.shields.io/badge/Happy-Building!-ff69b4?style=flat-square&logo=heart)
