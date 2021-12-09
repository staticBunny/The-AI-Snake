#include "fruit.h"

class Snake
{
    vector<Block*> body; // Stores all Block objects part of the snake.
    bool dead; // Stores whether the snake is dead or not.
    public:
        Snake(int x, int y); // Initializes all private data members.
        void move(string direction); // Moves the snake one step in the given direction.
        void grow(); // Adds a new Block to the snake's tail.
        void die(); // Sets the snake's dead status to true.
        bool checkDead(){return dead;} // Returns the snake's dead status.
        vector<Block*> getBody(){return body;} // Returns the snake's body.
};

Snake::Snake(int x, int y)
{
    dead = false;
    Block *head = new Block(x, y);
    body.push_back(head);
}

void Snake::move(string direction)
{
    int x = body.front()->getX();
    int y = body.front()->getY();
    if (direction == "up")
    {
        y--;
    }
    else if (direction == "down")
    {
        y++;
    }
    else if (direction == "left")
    {
        x--;
    }
    else if (direction == "right")
    {
        x++;
    }
    Block *newHead = body.back();
    body.pop_back();
    newHead->move(x, y);
    body.insert(body.begin(), newHead);
}

void Snake::grow()
{
    int x = body.back()->getX();
    int y = body.back()->getY();
    Block *newBlock = new Block(x, y);
    body.push_back(newBlock);
}

void Snake::die()
{
    dead = true;
    for(int i = 0; i < body.size(); ++i)
    {
        body[i]->color(FL_RED);
    }
}