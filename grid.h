#include "snake.h"
#include <queue>

#define WINDOW_SIZE 1000   

class Grid : public Fl_Window
{
     Fruit *fruit;
     Snake *snake;
     string snake_direction;
     queue<string> input_buffer;
     public:
        Grid();
        void grow_snake();
        void move_snake();
        void checkCollision();
        void control_snake();
        void update();
};

Grid::Grid() : Fl_Window(WINDOW_SIZE, WINDOW_SIZE)
{
    color(FL_BLACK);
    snake = new Snake(1,0);
    fruit = new Fruit(5,5);
    snake_direction = "right";
    show();
}

void Grid::grow_snake()
{
    snake->grow();
    add(snake->getBody().back());
}

void Grid::move_snake()
{
    control_snake();
    if(!input_buffer.empty())
    {
        snake_direction = input_buffer.front();
        input_buffer.pop();
    }
    snake->move(snake_direction);
}

void Grid::checkCollision()
{
    vector<Block*> body = snake->getBody();
    int x = body.front()->getX();
    int y = body.front()->getY();
    if(x == fruit->getX() && y == fruit->getY())
    {
        grow_snake();
        fruit->update();
    }
    if(x < 0 || x >= WINDOW_SIZE/BLOCK_SIZE || y < 0 || y >= WINDOW_SIZE/BLOCK_SIZE)
    {
        snake->die();
        return;
    }
    for(int i = 1; i < body.size(); i++)
    {
        if(body[i]->getX() == x && body[i]->getY() == y)
        {
            snake->die();
        }
    }
}

void Grid::control_snake()
{
    if(Fl::event_key(FL_Left))
    {
        if(snake_direction != "right")
        {
            input_buffer.push("left");
        }
        return;
    }
    else if(Fl::event_key(FL_Right))
    {
        if(snake_direction != "left")
        {
            input_buffer.push("right");
        }
        return;
    }
    else if(Fl::event_key(FL_Up))
    {
        if(snake_direction != "down")
        {
            input_buffer.push("up");
        }
        return;
    }
    else if(Fl::event_key(FL_Down))
    {
        if (snake_direction != "up")
        {
            input_buffer.push("down");
        }
        return;
    }
}

void Grid::update()
{
    if(!snake->checkDead())
        move_snake();
        checkCollision();
}
