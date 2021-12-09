#include "imports.h"
#include "grid.h"

void update_ai(void *game) // Updates the grid after every AI_TIME interval. This funtion is called when the "AI" argument is given in the command line.
{
    Grid *grid = (Grid *)game;
    grid->update("AI");
    Fl::repeat_timeout(AI_TIME, update_ai, grid);
}

void update_user(void *game) // Updates the grid after every USER_TIME interval. This function is called when the "AI" argument is not given in the command line.
{
    Grid *grid = (Grid *)game;
    grid->update("Human");
    Fl::repeat_timeout(USER_TIME, update_user, grid);
}

int main(int argc, char** argv) // Main function of the program. It creates a grid and starts the game.
                                // The parameter argv takes in command line prompts. This decides whether the game is played by the user or the AI.
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