# The-AI-Snake

The AI Snake is similar to the classic Snake game, where the objective is to eat as many fruits as possible. The game can either be played by a human, who can control the snake by using the arrow keys, or by an AI, which will try to find the best path from the snake to the fruit. 


### Header files
---

**imports.h** - contains necessary libraries and defines global variables.

**block.h** - contains the Block class. This is the base class from which Snake and Food are built.

**food.h** - contains the Food class. A food object is placed on the screen and updates to a new location when the snake eats it.

**snake.h** - contains the Snake class. A snake object is placed on the screen and updates to a new location when the snake moves.

**grid.h** - contains the Grid class. Grid is the main class that contains the game logic. It initializes a game window, and implements all necessay functions to run the game. Note that the AI agent is implemented in this class.

**point.h** - contains the Point class. This class is used to store the x and y coordinates of a block (mainly used by the AI agent). 

---
### Main

The main.cpp file contains the main function that runs the game. Note that to run the game you need to enter a command line argument. If the argument enetered is "AI", then the game will run in AI mode, i.e., the AI agent would be controlling the snake's movement. Otherwise, the game will run in normal mode, where the user controls the snake.
