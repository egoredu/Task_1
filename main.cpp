#include "Paint.h"
#include "Circle.h"
#include "Line.h"
#include "Edge.h"
#include "Node.h"
#include "Graph.h"

int main() {
    int gd = CUSTOM;
    int gm = CUSTOM_MODE(1280, 720);
    int n;
    vector< vector<int> > matr;
    cout << "Enter n: " << '\n';
    cin >> n;
    cout << "Enter weight matrix: " << '\n';
    matr.resize(n);
    for (int i = 0; i < n; i++){
        matr[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> matr[i][j];
    }
    Graph g(n, matr);
    initgraph(&gd, &gm, "");
    g.Draw();
    readkey();
    int start;
    cout << "Enter the start node for Dijkstra algorithm: ";
    cin >> start;
    g.Dijkstra(start - 1);
    readkey();
    return 0;
}
