#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define BLOCK_SIZE 50 // Size of each Fl_Box
#define WINDOW_SIZE 1000 // Size of the Fl_Window
#define GRID_SIZE WINDOW_SIZE/BLOCK_SIZE // Resulting size of the grid

#define AI_TIME 0.001 // Time between each AI move
#define USER_TIME 0.1 // Time between each user move

using namespace std;
