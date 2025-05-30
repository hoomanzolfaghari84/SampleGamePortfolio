# HEngine Game Project
---

**HEngine** (short for **Hooman Engine**) is a modular, ECS-based C++ game engine developed as a learning and creative project inspired by [The Cherno](https://github.com/TheCherno)'s Hazel engine. It uses **SFML** as its graphics backend and **spdlog** for logging.

This repository contains a Visual Studio (MSVC) solution with two projects:

- **Engine** – The core of HEngine, including ECS, logging, and abstraction layers. Currently built as a Dynamic Linked Library.
- **TurnoverGame** – A sample turn-based game built using the engine, serving as an example client.

---

## 📦 Features

- **Entity-Component-System (ECS)** architecture
- **Clean and Modular project structure**
- **SFML backend** for rendering, input, and windowing (abstracted so it can be replaced)
- **spdlog** for high-performance, modern logging (abstracted so it can be replaced)
- **Clean separation** of engine and game logic
- **Project Setup Inspired by Hazel** (but fully built from scratch!)

---

## 🧠 Project Inspiration

This engine is part of my personal journey to understand and build game technology from the ground up. Special thanks to **The Cherno** and his Hazel series for the architectural insights and inspiration.

---

## 🔧 Dependencies

- [SFML](https://www.sfml-dev.org/) – version 3.xx - Rendering and windowing
- [spdlog](https://github.com/gabime/spdlog) – Logging

Both dependencies are configured via Visual Studio and may need to be installed or linked manually depending on your setup. 
One can also replace them by making changes to the Rendering System APIs and Logging utility APIs.

---

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/hoomanzolfaghari84/SampleGamePortfolio.git
cd HEngine
````

### 2. Open the Solution

Open `SampleGame.sln` in Visual Studio (2022 or later recommended).

### 3. Build and Run

* Set the startup project to `TurnoveGamer`.
* Build the solution.
* Run and enjoy the demo game!

---

## 📁 Project Structure

```
SampleGame.sln/               # Visual Studio solution
├── Engine.prj/               # Core engine (ECS, utilities, SFML abstraction)
│   ├── src/
│   │   ├── HEngine/
│   │   │   ├── Core          # Base application, entry point, GameEngine, etc.
│   │   │   ├── ECS           # EntityManager, ComponentManager, SystemManager, Coordinator, Scene base, etc.
│   │   │   ├── Events        # Event system
│   │   │   ├── Utils         # HVector2D, HLogger, HMath, HColor, etc.
│   │   ├── HEngine.h         # Client-facing include file
│   │   ├── hepch.h/cpp       # Precompiled headers
│   ├── vendors/
│       ├── SFML
│       ├── spdlog
├── TurnoverGame.prj/         # Client project (demo game using HEngine)
│   ├── src/
│   │   └── TurnoverGame.cpp  # Client application class
└── README.md                 # You're here!
```

---

## 🎮 Turnover – Demo Game

**Turnover** is a simple turn-based client game built on top of HEngine to demonstrate the ECS workflow and system integration. It's a playground for engine testing and a base for expanding gameplay ideas.

---

## ✍️ Author

**Hooman Zolfaghari**
Computer Science, Sharif University of Technology

> Building HEngine to explore game engine architecture, ECS design, and C++ programming.

---

## 📜 License

This project is released under the MIT License. See `LICENSE` for details.

---

## 🌟 Future Plans

* Currently, the project is in very early stages.

---

Thanks for checking out HEngine! Contributions, feedback, and forks are welcome.



