#include "Circle.h"

Circle::Circle()
{
#ifdef DEBUG
    cout << "Circle()\n";
#endif // DEBUG
}

Circle::~Circle()
{
#ifdef DEBUG
    cout << "~Circle()\n";
#endif // DEBUG
}

Circle::Circle(int x, int y, int r) : x_center(x), y_center(y), radius(r)
{
#ifdef DEBUG
    cout << "Circle(int, int, int)\n";
#endif // DEBUG
}

void Circle::setx(int x)
{
    x_center = x;
#ifdef DEBUG
    cout << "Circle::setx(int)\n";
#endif // DEBUG
}

void Circle::sety(int y)
{
    y_center = y;
#ifdef DEBUG
    cout << "Circle::sety(int)\n";
#endif // DEBUG
}

void Circle::setr(int r)
{
    radius = r;
#ifdef DEBUG
    cout << "Circle::setr(int)\n";
#endif // DEBUG
}

int Circle::getx()
{
#ifdef DEBUG
    cout << "Circle::getx()\n";
#endif // DEBUG
    return x_center;
}

int Circle::gety()
{
#ifdef DEBUG
    cout << "Circle::gety()\n";
#endif // DEBUG
    return y_center;
}

int Circle::getr()
{
#ifdef DEBUG
    cout << "Circle::getr()\n";
#endif // DEBUG
    return radius;
}

void Circle::Draw()
{
    circle(x_center, y_center, radius);
#ifdef DEBUG
    cout << "Circle::Draw\n";
#endif // DEBUG
}
