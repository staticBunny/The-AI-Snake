#include "imports.h"
#include "grid.h"

void update_ai(void *game)
{
    Grid *grid = (Grid *)game;
    grid->update("AI");
    Fl::repeat_timeout(AI_TIME, update_ai, grid);
}

void update_user(void *game)
{
    Grid *grid = (Grid *)game;
    grid->update("Human");
    Fl::repeat_timeout(USER_TIME, update_user, grid);
}

int main(int argc, char** argv)
{
    Grid *game = new Grid();
    string ans = argv[1];
    if(ans == "AI")
    {
        Fl::add_timeout(AI_TIME, update_ai, game);
    }
    else
    {
        Fl::add_timeout(USER_TIME, update_user, game);
    }
    
    return Fl::run();
}