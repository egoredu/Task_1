#ifndef CIRCLE_H
#include "Paint.h"
#define CIRCLE_H


class Circle : public Paint
{
    public:
        Circle();
        Circle(int x, int y, int r);
        virtual ~Circle();
        void setx(int x);
        void sety(int y);
        void setr(int r);
        void Draw();
        int getx();
        int gety();
        int getr();
    protected:

    private:
        int x_center, y_center, radius;
};

#endif // CIRCLE_H
