#include "imports.h"
#include "snake.h"
#include "point.h"

class Grid : public Fl_Window
{
    Fruit *fruit;
    Snake *snake;
    string snake_direction;
    queue<string> input_buffer;

public:
    Grid();
    bool check_for_snake(int x, int y);
    bool is_snake(Point *p);
    bool is_wall(Point *p);
    void grow_snake();
    void move_snake(string game_mode);
    void move_fruit();
    void checkCollision();
    void control_snake();
    vector<Point *> get_neighbors(Point *p);
    int cost_to_fruit(Point *p);
    int lowest_cost_index(vector<Point *> list);
    vector<Point *> get_path();
    Point *get_next_move();
    void set_ai_path();
    void update(string game_mode);
};

Grid::Grid() : Fl_Window(WINDOW_SIZE, WINDOW_SIZE)
{
    color(FL_BLACK);
    snake = new Snake(1, 0);
    fruit = new Fruit(5, 5);
    snake_direction = "right";
    show();
}

bool Grid::check_for_snake(int x, int y)
{
    vector<Block *> body = snake->getBody();
    for (int i = 0; i < snake->getBody().size(); i++)
    {
        if (body[i]->getX() == x && body[i]->getY() == y)
        {
            return true;
        }
    }
    return false;
}

bool Grid::is_snake(Point *p)
{
    vector<Block *> body = snake->getBody();
    for (int i = 0; i < body.size(); i++)
    {
        if (body[i]->getX() == p->x && body[i]->getY() == p->y)
        {
            return true;
        }
    }
    return false;
}

bool Grid::is_wall(Point *p)
{
    if (p->x < 0 || p->x >= WINDOW_SIZE / BLOCK_SIZE || p->y < 0 || p->y >= WINDOW_SIZE / BLOCK_SIZE)
    {
        return true;
    }
    return false;
}

void Grid::grow_snake()
{
    snake->grow();
    add(snake->getBody().back());
}

void Grid::move_snake(string game_mode)
{
    if (game_mode == "AI")
    {
        set_ai_path();
    }
    else
    {
        control_snake();
    }
    if (!input_buffer.empty())
    {
        snake_direction = input_buffer.front();
        input_buffer.pop();
    }
    snake->move(snake_direction);
}

void Grid::move_fruit()
{
    fruit->update();
    int x = fruit->getX();
    int y = fruit->getY();
    if (check_for_snake(x, y))
    {
        for (int i = x; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (!check_for_snake(i, j))
                {
                    fruit->move(i, j);
                    return;
                }
            }
        }
        for (int i = x - 1; i >= 0; i--)
        {
            for (int j = GRID_SIZE - 1; j >= 0; j--)
            {
                if (!check_for_snake(i, j))
                {
                    fruit->move(i, j);
                    return;
                }
            }
        }
    }
}

void Grid::checkCollision()
{
    vector<Block *> body = snake->getBody();
    int x = body.front()->getX();
    int y = body.front()->getY();
    if (x == fruit->getX() && y == fruit->getY())
    {
        grow_snake();
        move_fruit();
    }
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE)
    {
        snake->die();
        return;
    }
    for (int i = 1; i < body.size(); i++)
    {
        if (body[i]->getX() == x && body[i]->getY() == y)
        {
            snake->die();
        }
    }
}

void Grid::control_snake()
{
    if (Fl::event_key(FL_Left))
    {
        if (snake_direction != "right")
        {
            input_buffer.push("left");
        }
        return;
    }
    else if (Fl::event_key(FL_Right))
    {
        if (snake_direction != "left")
        {
            input_buffer.push("right");
        }
        return;
    }
    else if (Fl::event_key(FL_Up))
    {
        if (snake_direction != "down")
        {
            input_buffer.push("up");
        }
        return;
    }
    else if (Fl::event_key(FL_Down))
    {
        if (snake_direction != "up")
        {
            input_buffer.push("down");
        }
        return;
    }
}

vector<Point *> Grid::get_neighbors(Point *p)
{
    vector<Point *> neighbors;
    Point *up = new Point(p->x, p->y - 1);
    if (!is_snake(up) && !is_wall(up))
    {
        neighbors.push_back(up);
    }
    Point *down = new Point(p->x, p->y + 1);
    if (!is_snake(down) && !is_wall(down))
    {
        neighbors.push_back(down);
    }
    Point *left = new Point(p->x - 1, p->y);
    if (!is_snake(left) && !is_wall(left))
    {
        neighbors.push_back(left);
    }
    Point *right = new Point(p->x + 1, p->y);
    if (!is_snake(right) && !is_wall(right))
    {
        neighbors.push_back(right);
    }
    return neighbors;
}

int Grid::cost_to_fruit(Point *p)
{
    int x = fruit->getX();
    int y = fruit->getY();
    int cost = abs(x - p->x) + abs(y - p->y);
    return cost;
}

int Grid::lowest_cost_index(vector<Point *> list)
{
    int lowest_cost = cost_to_fruit(list[0]);
    int lowest_index = 0;
    for (int i = 1; i < list.size(); i++)
    {
        if (cost_to_fruit(list[i]) < lowest_cost)
        {
            lowest_cost = cost_to_fruit(list[i]);
            lowest_index = i;
        }
    }
    return lowest_index;
}

Point *Grid::get_next_move()
{
    Point *current = new Point(snake->getBody().front()->getX(), snake->getBody().front()->getY());
    vector<Point *> open = get_neighbors(current);
    if (open.size() == 0)
    {
        current = new Point(current->x + 1, current->y);
    }
    else
    {
        current = open[lowest_cost_index(open)];
    }
    return current;
}

void Grid::set_ai_path()
{
    Point *next = get_next_move();
    int snake_x = snake->getBody().front()->getX();
    int snake_y = snake->getBody().front()->getY();
    if (next->x == snake_x + 1 && next->y == snake_y)
    {
        input_buffer.push("right");
    }
    else if (next->x == snake_x - 1 && next->y == snake_y)
    {
        input_buffer.push("left");
    }
    else if (next->x == snake_x && next->y == snake_y + 1)
    {
        input_buffer.push("down");
    }
    else if (next->x == snake_x && next->y == snake_y - 1)
    {
        input_buffer.push("up");
    }
}


void Grid::update(string game_mode)
{
    if (!snake->checkDead())
        move_snake(game_mode);
        checkCollision();
}
