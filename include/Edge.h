#ifndef EDGE_H
#include "Line.h"
#include "Circle.h"
#include "Paint.h"
#define EDGE_H

class Edge: public Line
{
public:
	Edge();
	Edge(int xb, int yb, int xe, int ye, int w);
	~Edge();
	void setBegin(int x, int y);
	void setEnd(int x, int y);
	void setweight(int w);
	void reSet(int xb, int yb, int xe, int ye, int w);
	void Draw();
private:
    char* weight;
};

#endif
