#ifndef PAINT_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <queue>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;
#define PAINT_H
//#define DEBUG

#define PI 3.14159

class Paint
{
    public:
        virtual void Draw() = 0; // Draw will be defined later
};

#endif // PAINT_H
