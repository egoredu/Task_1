#pragma once
#ifndef GRAPH_H
#include "Paint.h"
#include "Node.h"
#include "Edge.h"
#include <fstream>
#define GRAPH_H
#define INF 100000

class Graph : public Paint
{
    public:
        Graph();
        Graph(int k, const vector < vector <int> > &a);
        virtual ~Graph();
        void input();
        //pair <pair <int, int>> newxy(Node start, Node finish);
        //void DrawEdge(int i, int j);
        void Draw();
        void Dijkstra(int from);
    protected:

    private:
        int n, rad;
        vector < vector <int> > matrix;
        vector <Node> nodes;
        //vector <Edge> edges;
};
//just comment
#endif // GRAPH_H
