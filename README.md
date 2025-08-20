# 🎮 Blockbuster Game – C++ SFML Project

![SFML Logo](https://www.sfml-dev.org/images/logo.png)

## 📖 Overview
**Blockbuster Game** is a simple yet engaging project built in **C++** using the **SFML graphics library**.  
The core idea is to showcase **game development fundamentals** with graphics rendering, object duplication, and screen interactions.  

The game starts with a **single block**, and as soon as it touches the **edges of the screen**, it **duplicates itself**. Over time, the screen becomes filled with blocks, creating a fun and visually appealing chaos!

---

## 🎯 Gameplay Objective
- Start with a single block on the screen.
- Each time a block touches the **screen boundary**, it **duplicates**.
- Keep playing until the **screen is completely filled with blocks**.

---

## 🛠 Features
- ✅ Built using **C++** and **SFML Graphics Library**  
- ✅ **Dynamic block duplication** when hitting edges  
- ✅ **Interactive animation** filling up the screen  
- ✅ Demonstrates **game development fundamentals**  
- ✅ Simple yet **addictive gameplay loop**  

---

## 🎮 Controls
This game runs automatically – no controls needed!  
Just watch the blocks duplicate and fill the screen.  

---

## ⚙️ Installation & Setup

### 1️⃣ Prerequisites
- **C++ Compiler** (GCC, MinGW, MSVC, etc.)
- **SFML Library** ([Download here](https://www.sfml-dev.org/download.php))

### 2️⃣ Clone the Repository
```bash
git clone https://github.com/TahaGPT/TheBlockbuster-Game.git
cd TheBlockbuster-Game
```

### 3️⃣ Build & Run
```bash
g++ main.cpp -o blockbuster -lsfml-graphics -lsfml-window -lsfml-system
./blockbuster
```

