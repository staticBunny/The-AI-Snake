#include "block.h"


using namespace std;

class Fruit : public Block
{
    public:
        Fruit(int x, int y);
        void update();
};

Fruit::Fruit(int x, int y) : Block(x, y)
{
    color(FL_YELLOW);
}

void Fruit::update()
{
    int x = (rand() % 20);
    int y = (rand() % 20);
    move(x, y);
}

