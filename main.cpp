#include "grid.h"

#define REFRESH_RATE 0.1

void update(void *game)
{
    Grid *grid = (Grid *)game;
    grid->update();
    Fl::repeat_timeout(REFRESH_RATE, update, grid);
}

int main()
{
    Grid *game = new Grid();
    Fl::add_timeout(REFRESH_RATE, update, game);
    return Fl::run();
}