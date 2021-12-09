#include "imports.h"

class Point
{
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point &p) const
    {
        return (x == p.x && y == p.y);
    }
    void print()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};