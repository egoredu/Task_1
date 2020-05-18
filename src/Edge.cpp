#include "Edge.h"

Edge::Edge()
{
#ifdef DEBUG
    cout << "Edge\n";
#endif // DEBUG
}

Edge::Edge(int xb, int yb, int xe, int ye, int w) : Line(xb, yb, xe, ye), weight(new char[4])
{
#ifdef DEBUG
    cout << "Edge(int, int, int, int, int)\n";
#endif // DEBUG
    itoa(w, weight, 10);
}

Edge::~Edge()
{
#ifdef DEBUG
    cout << "~Edge\n";
#endif // DEBUG
}

void Edge::setBegin(int x, int y)
{
#ifdef DEBUG
    cout << "Edge::setBegin(int, int)\n";
#endif // DEBUG
    x1 = x;
    y1 = x;
}

void Edge::setEnd(int x, int y)
{
#ifdef DEBUG
    cout << "Edge::setEnd(int, int)\n";
#endif // DEBUG
    x2 = x;
    y2 = x;
}

void Edge::setweight(int w)
{
#ifdef DEBUG
    cout << "Edge::setweight(int)\n";
#endif // DEBUG
    weight = new char[4];
    itoa(w, weight, 10);
}

void Edge::reSet(int xb, int yb, int xe, int ye, int w)
{
#ifdef DEBUG
    cout << "Edge::reSet(int, int, int, int, int)\n";
#endif // DEBUG
    setBegin(xb, yb);
    setEnd(xe, ye);
    setweight(w);
}

void Edge::Draw()
{
#ifdef DEBUG
    cout << "Edge::Draw()\n";
#endif // DEBUG
    Line::Draw();
    double length = sqrt((double)pow(getx2() - getx1(), 2) + (double)pow(gety2() - gety1(), 2));
    double cosL = (double)(getx2() - getx1()) / length; //косинус угла наклона линии
    double sinL = (double)(gety2() - gety1()) / length; //синус угла наклона линии
    double cosUP = cosL * cos(PI / 6) - sinL * sin(PI / 6); //косинус того же угла
    double sinUp = sinL * cos(PI / 6) + sin(PI / 6) * cosL; //синус угла наклона верхней динии стрелочки
    double sinLo = sinL * cos(PI / 6) - sin(PI / 6) * cosL;
    double cosLo = cosL * cos(PI / 6) + sinL * sin(PI / 6);
    double l = 10.0;
    double lx_end = getx2() - l * cosLo;
    double ly_end = gety2() - l * sinLo;
    double ux_end = getx2() - l * cosUP;
    double uy_end = gety2() - l * sinUp;
    line(getx2(), gety2(), (int)lx_end, (int)ly_end);
    line(getx2(), gety2(), (int)ux_end, (int)uy_end);
   /* char *s;
    s = itoa(weight, s, 10);*/
    outtextxy((2 * getx1() + getx2()) / 3, (2 * gety1() + gety2()) / 3, weight);
}
