#include "imports.h"

class Block : public Fl_Box
{
    public:
        Block(int x, int y); //Initialises an Fl_Box object by setting appropiate size, shape and color.
        void move(int x, int y); //Moves the Fl_Box to a new point (x,y).
        int getX(); //Returns the x coordinate of the Fl_Box.
        int getY(); //Returns the y coordinate of the Fl_Box.
};

Block::Block(int x, int y) : Fl_Box(x*BLOCK_SIZE, y*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE)
{
    box(FL_FLAT_BOX);
    color(FL_GREEN);
    show();
}

void Block::move(int x, int y)
{
    hide();
    position(x*BLOCK_SIZE, y*BLOCK_SIZE);
    show();
}

int Block::getX()
{
    return (x()/BLOCK_SIZE);
}

int Block::getY()
{
    return (y()/BLOCK_SIZE);
}