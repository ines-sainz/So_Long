# 🐬 so\_long

**And thanks for all the fish!**

## 🎮 About the Project

`so_long` is a small 2D game designed as an introduction to graphics programming using the MiniLibX library. It challenges you to implement basic game mechanics, window and image rendering, and map parsing in C. You'll get a taste of building your own game world — where the player must collect all items and find the exit!

---

## 📌 Project Goals

This project aims to introduce you to:

* Basic 2D game logic
* Window and image rendering
* Texture and sprite management
* Event handling (keyboard/mouse)
* Map parsing and validation
  All using the MiniLibX graphics library.

---

## 📁 What You’ll Implement

### 🔹 The Game

* Control your player using `W`, `A`, `S`, `D`
* Collect all the collectibles on the map
* Find the shortest path to the exit
* Avoid walking into walls
* View your movement count in the terminal

### 🖼️ Graphics Management

* A window that displays the game in 2D (top-down or side view)
* Clean handling of window events (close, minimize, etc.)
* Exit gracefully when pressing `ESC` or clicking the red cross
* All images must be drawn using MiniLibX

### 🗘️ The Map

* Built with characters:

  * `1`: Wall
  * `0`: Empty space
  * `C`: Collectible
  * `E`: Exit
  * `P`: Player start position
* Must be rectangular and enclosed by walls
* Must contain at least one `C`, one `E`, and one `P`
* Must validate the existence of a valid path
* Example:

  ```
  111111
  1P0C01
  100001
  1E0001
  111111
  ```

---

## ⚙️ Requirements

* Language: **C**
* Use of **MiniLibX** and optionally **libft**
* Deliverables:

  * `Makefile` with rules: `all`, `clean`, `fclean`, `re`, `bonus`
  * Source files (`*.c`, `*.h`), maps, textures
* Compilation flags: `-Wall -Wextra -Werror`
* Must free all heap memory properly
* Must handle all errors gracefully (output: `Error\n` + message)
