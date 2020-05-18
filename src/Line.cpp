#include "Line.h"

Line::Line()
{
#ifdef DEBUG
    cout << "Line()\n";
#endif // DEBUG
}

Line::~Line()
{
#ifdef DEBUG
    cout << "~Line()\n";
#endif // DEBUG
}

Line::Line(int xb, int yb, int xe, int ye) : x1(xb), y1(yb), x2(xe), y2(ye)
{
#ifdef DEBUG
    cout << "Line(int, int ,int, int)\n";
#endif // DEBUG
}

void Line::setBegin(int x, int y)
{
    x1 = x;
    y1 = y;
#ifdef DEBUG
    cout << "Line::setBegin(int ,int)\n";
#endif // DEBUG
}

void Line::setEnd(int x, int y)
{
    x2 = x;
    y2 = y;
#ifdef DEBUG
    cout << "Line::setEnd(int, int)\n";
#endif // DEBUG
}

void Line::Draw()
{
    line(x1, y1, x2, y2);
#ifdef DEBUG
    cout << "Line::Draw()\n";
#endif // DEBUG
}

int Line::getx1()
{
#ifdef DEBUG
    cout << "Line::getx1()\n";
#endif // DEBUG
    return x1;
}

int Line::getx2()
{
#ifdef DEBUG
    cout << "Line::getx2()\n";
#endif // DEBUG
    return x2;
}

int Line::gety1()
{
#ifdef DEBUG
    cout << "Line::gety1()\n";
#endif // DEBUG
    return y1;
}

int Line::gety2()
{
#ifdef DEBUG
    cout << "Line::gety2()\n";
#endif // DEBUG
    return y2;
}
