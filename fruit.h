#include "block.h"


using namespace std;

class Fruit : public Block
{
    public:
        Fruit(int x, int y); // Initializes a new Block object to (x,y) and changes Block color.
        void update(); // Moves the Block to a random location on the screen.
};

Fruit::Fruit(int x, int y) : Block(x, y)
{
    color(FL_YELLOW);
}

void Fruit::update()
{
    int x = (rand() % GRID_SIZE);
    int y = (rand() % GRID_SIZE);
    move(x, y);
}

