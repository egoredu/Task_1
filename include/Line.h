#pragma once
#ifndef LINE_H
#include "Paint.h"
#define LINE_H


class Line : public Paint
{
    public:
        Line();
        Line(int xb, int yb, int xe, int ye);
        virtual ~Line();
        void setBegin(int x, int y);
        void setEnd(int x, int y);
        void Draw();
        int getx1();
        int getx2();
        int gety1();
        int gety2();

    protected:
        int x1, y1, x2, y2;
};

#endif // LINE_H
