# 🎮 Assignment 2 – Console Game Analysis & Enhancements

## 📘 Overview
This repository contains the analysis and modified version of a lane-based console game made in **C**.  
The assignment required understanding an existing game, applying enhancements, and documenting the improvements.

The final game now includes:
- ✅ Score System  
- ✅ Player Lives  
- ✅ High Score Storage (File Handling)  
- ✅ Restart Option  
- 🎨 Improved Visuals  

---

## 🕹️ Game Description
The game is a simple console-based **lane runner** where:
- The player controls a `^` symbol.
- An obstacle `@` falls from the top.
- The player must avoid the obstacle by switching between three lanes.
- Score increases on each successful dodge.
- Player gets **3 lives** before losing.
- High score is saved in a file (`highscore.txt`).

---

## 🧠 Understanding the Game Logic

### 📌 Key Variables
| Variable     | Purpose                                      |
|--------------|----------------------------------------------|
| `x`          | Player lane position (0–2)                   |
| `step`       | Vertical progress of falling obstacle        |
| `obstaclePos`| Lane containing the obstacle                 |
| `score`      | Counts successful dodges                     |
| `lives`      | Player health (starts at 3)                  |
| `highScore`  | Loaded/stored using file handling            |

### 📌 Input Handling
Handled through **conio.h**:
- ⬅️ Left Arrow → Move left  
- ➡️ Right Arrow → Move right  

---

## 🛠️ Modifications Implemented
✔ **Score System** – Counter increases every time the player avoids an obstacle.  
✔ **Player Lives** – Player gets 3 lives; collision reduces one life; game ends at 0.  
✔ **High Score System (File Handling)** – Persistent high score saved in `highscore.txt`.  
✔ **Restart Option** – After game over, player can restart by pressing:  
   - `Y` → Restart  
   - `N` → Exit  

**Total Features Implemented:**
- 1 High-Level Feature  
- 2 Simple Features  
➡️ Requirement Completed ✅  

---

## 🎨 Game Preview (ASCII Layout)
|--- --- ---|
|           |
|     @     |
|           |
|           |
|           |
|     ^     |
Score: 5   Lives: 2   High Score: 16
