#ifndef NODE_H
#include "Paint.h"
#include "Circle.h"
#define NODE_H


class Node : public Circle
{
    public:
        Node();
        Node(int x, int y, int r, int n);
        virtual ~Node();
        void Draw();
        //void setx(int x);
        //void sety(int y);
        //void setr(int r);
        void setnum(int num);
        void reSet(int x, int y, int r, int num);
    protected:

    private:
        //int x_center, y_center, radius;
        char *num;
};

#endif // NODE_H
