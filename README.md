# 🚀 HEngine & Turnover Game

**HEngine** is a lightweight, modular 2D game engine built with C++ and [SFML](https://www.sfml-dev.org/), designed for rapid development and educational purposes.
**Turnover** is a sample game developed using HEngine to demonstrate its capabilities, including a basic menu system, entity/component architecture, and scene management.

---

## 📸 Screenshots

> *(Include a few in-game screenshots or editor shots here, if available)*

---

## ✨ Features

### 🔧 HEngine (Core Engine)

* 🔌 **Modular architecture** with support for scenes, components, and entity management
* 🧩 **Component system** for behavior composition
* 📜 **Scene abstraction** (base `Scene` class with derived `MenuScene`, etc.)
* 🧠 **Custom logging system** using `spdlog`
* 🖱️ **Mouse interaction** with collision box support
* 🏗️ **SFML backend** for graphics, input, and window management

### 🎮 Turnover (Sample Game)

* 🧭 Main menu with button entities
* 💡 Hover and click effects using collision components
* 🖼️ Clean entity creation & rendering pipeline
* 🧼 Serves as a starting point for building your own game

---

## 🏁 Getting Started

### 🔨 Prerequisites

* [Visual Studio 2022](https://visualstudio.microsoft.com/)
* [SFML 3.x](https://www.sfml-dev.org/)
* CMake (optional, depending on setup)

### 🧱 Cloning the Repository

```bash
git clone https://github.com/yourusername/HEngine.git
cd HEngine
```

### ▶️ Build Instructions (Visual Studio)

1. Open `HEngine.sln`
2. Set **Engine** and **TurnoverGame** to build as **Debug/Release x64**
3. Ensure compiler flag `/utf-8` is set for all projects
4. Build & run the `TurnoverGame` project

---

## 📁 Project Structure

```
/Engine
  ├─ src/HEngine
  │   ├─ Core/
  │   ├─ ECS/
  │   ├─ Scenes/
  │   ├─ Utils/
  ├─ vendors/
  │   └─ spdlog/
  └─ CMakeLists.txt (if using CMake)
/TurnoverGame
  ├─ src/
  │   ├─ MenuScene.cpp
  │   └─ TurnoverGame.cpp
```

---

## 📦 Dependencies

* [SFML](https://www.sfml-dev.org/) — graphics, input, windowing
* [spdlog](https://github.com/gabime/spdlog) — logging
* [fmtlib](https://github.com/fmtlib/fmt) — formatting backend for spdlog

---

## 📋 Build Badges (Optional)

&#x20;&#x20;

---

## 🙌 Contributing

Pull requests are welcome! If you have ideas or improvements, feel free to fork the repo and submit a PR.

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

---

## ✍️ Author

[**@yourusername**](https://github.com/yourusername)
If you found this useful, give it a ⭐ and share your feedback!
