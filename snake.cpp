#include "fruit.cpp"
#include <vector>

class Snake
{
    vector<Block*> body;
    bool dead;
    public:
        Snake(int x, int y);
        void move(string direction);
        void grow();
        //void die(){dead = true;}
        void die();
        bool checkDead(){return dead;}
        vector<Block*> getBody(){return body;}
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
    Block *newBlock = new Block(x-1, y);
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