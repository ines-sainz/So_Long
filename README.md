# So Long 🐬

`so_long` is a small 2D game designed as an introduction to graphics programming using the MiniLibX library.
It challenges to implement basic game mechanics, window and image rendering, and map parsing in C using textures, sprites and basic gameplay elements.

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

## 🎯 Features

- **Movement**: Use W, A, S, D keys to move the character in 4 directions
- **Objective**: Collect all items and reach the exit using the shortest possible route
- **Collision**: Player cannot move through walls
- **Move Counter**: Display movement count in terminal after each move
- **2D Perspective**: Bird's eye view or side view gameplay
- **Clean Window Management**: Proper window handling, minimize, switch windows
- **Exit Controls**: ESC key or red X button to close window and exit cleanly
- **Map Validation**: Check for valid path, proper map structure, and error handling
- **Enemy Patrols**: Player loses when touching enemy patrols
- **Sprite Animations**: Added sprite animations for enhanced visual experience
- **On-Screen Counter**: Movement counter displayed directly on screen instead of terminal

---

## 🗺️ Map Format

Maps use `.ber` extension and consist of 5 characters:
- `0` - Empty space
- `1` - Wall
- `C` - Collectible
- `E` - Exit
- `P` - Player starting position

### Map Requirements:
- Must be rectangular
- Surrounded by walls
- Contains exactly one exit and one starting position
- At least one collectible
- Must have a valid path to complete the game

### Example Map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## 🎮 Controls

| Key | Action |
|-----|--------|
| W/↑ | Move Up |
| S/↓ | Move Down |
| A/← | Move Left |
| D/→ | Move Right |
| ESC | Exit Game |


## ⚠️ Error Handling

The program handles various error cases:
- Invalid map format
- Invalid characters in map
- Map not surrounded by walls
- No valid path to complete the game
- Missing required elements (player, exit, collectibles)
- Duplicate players or exits

All errors display: `Error\n` followed by a descriptive message.
