#include "imports.h"

class Point
{
public:
    int x, y; // Store x and y coordinates.
    Point(int x, int y) : x(x), y(y) {} // Initializes x and y.
    bool operator==(const Point &p) const // Sets the equality operator.
    {
        return (x == p.x && y == p.y);
    }
    void print() // Prints the point.
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};