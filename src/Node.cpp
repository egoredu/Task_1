#include "Node.h"

Node::Node()
{
#ifdef DEBUG
    cout << "Node()\n";
#endif // DEBUG
}

Node::~Node()
{
#ifdef DEBUG
    cout << "~Node()\n";
#endif // DEBUG
}

Node::Node(int x, int y, int r, int n) : Circle(x, y, r), num(new char[4])
{
#ifdef DEBUG
    cout << "Node(int, int, int, int)\n";
#endif // DEBUG
    itoa(n, num, 10);
}
/*
void Node::setx(int x)
{
#ifdef DEBUG
    cout << "Node::setx(int)\n";
#endif // DEBUG
    x_center = x;
}

void Node::sety(int y)
{
#ifdef DEBUG
    cout << "Node::sety(int)\n";
#endif // DEBUG
    y_center = y;
}

void Node::setr(int r)
{
#ifdef DEBUG
    cout << "Node::setr(int)\n";
#endif // DEBUG
    radius = r;
}
*/
void Node::setnum(int n)
{
#ifdef DEBUG
    cout << "Node::setnum(int)\n";
#endif // DEBUG
    num = new char[4];
    itoa(n, num, 10);
}

void Node::reSet(int x, int y, int r, int n)
{
#ifdef DEBUG
    cout << "Npde::reSet(int, int, int, int)\n";
#endif // DEBUG
    setx(x);
    sety(y);
    setr(r);
    setnum(n);
}

void Node::Draw()
{
#ifdef DEBUG
    cout << "Node::Draw()\n";
#endif // DEBUG
    Circle::Draw();
    outtextxy(getx(), gety(), num);
}
