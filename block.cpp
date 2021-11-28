#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>

#define BLOCK_SIZE 50

using namespace std;

class Block : public Fl_Box
{
    public:
        Block(int x, int y);
        void move(int x, int y);
        int getX();
        int getY();
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