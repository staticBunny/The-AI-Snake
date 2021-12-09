#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define BLOCK_SIZE 50
#define WINDOW_SIZE 1000
#define GRID_SIZE WINDOW_SIZE/BLOCK_SIZE

#define AI_TIME 0.001
#define USER_TIME 0.1

using namespace std;
