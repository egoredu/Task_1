#include "Graph.h"
#define DBG

Graph::Graph()
{
#ifdef DEBUG
    cout << "Graph()\n";
#endif // DEBUG
}

Graph::Graph(int k, const vector< vector <int> > &a)
{
    rad = 200;
    n = k;
    matrix.resize(n);
    //nodes.resize(n);
    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(n);
        int x = 50 + (int) (rad * (1.0 - cos(2.0* PI *(double)i/(double)n)));
        int y = (int) (rad * (1.0 - sin (2.0 * PI * (double)i/(double)n))) + 80;
        nodes.push_back(Node(x, y, 30, i + 1));
        for (int j = 0; j < n; j++)
            matrix[i][j] = a[i][j];
    }

}

Graph::~Graph()
{
#ifdef DEBUG
    cout << "~Graph()\n";
#endif // DEBUG

}

void Graph::input()
{
#ifdef DEBUG
    cout << "Graph::input()\n";
#endif // DEBUG
    rad = 50;
    cout << "Enter the number of vertices: ";
    cin >> n;
    matrix.resize(n);
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        int x = (int) (rad * (1.0 - cos(2.0* PI *(double)i/(double)n)));
        int y = (int) (rad * (1.0 - sin (2.0 * PI * (double)i/(double)n)));
        nodes.push_back(Node(x, y, 30, i));
        matrix[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
}

void Graph::Draw()
{
#ifdef DEBUG
    cout << "Graph::Draw()\n";
#endif // DEBUG
    for (int i = 0; i < n; i++)
        nodes[i].Draw();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] > 0)
            {
                double length = sqrt(pow(nodes[i].getx() - nodes[j].getx(), 2) + pow(nodes[i].gety() - nodes[j].gety(), 2));
                //double cosL = (double)(nodes[j].getx() - nodes[i].getx()) / length; //косинус угла наклона линии
                //double sinL = (double)(nodes[j].gety() - nodes[i].gety()) / length; //синус угла наклона линии
                int xb = (nodes[i].getx() * (length - nodes[i].getr()) + nodes[j].getx() * nodes[i].getr()) / length;
                int yb = (nodes[i].gety() * (length - nodes[i].getr()) + nodes[j].gety() * nodes[i].getr()) / length;
                int xe = (nodes[j].getx() * (length - nodes[j].getr()) + nodes[i].getx() * nodes[j].getr()) / length;
                int ye = (nodes[j].gety() * (length - nodes[j].getr()) + nodes[i].gety() * nodes[j].getr()) / length;
                //Edge e(nodes[i].getx(), nodes[i].gety(), nodes[j].getx(), nodes[j].gety(), matrix[i][j]);
                Edge e(xb, yb, xe, ye, matrix[i][j]);
                e.Draw();
            }
}

void Graph::Dijkstra(int from)
{
#ifdef DEBUG
    cout << "Graph::Dijkstra(int)\n";
#endif // DEBUG
    vector <bool> used(n, false);
    vector <int> pred(n, -1);
    vector <int> dist(n);
    vector < vector <int> > costs(n);
    for (int i = 0; i < n; i++)
    {
        costs[i].resize(n);
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0) costs[i][j] = INF;
            else costs[i][j] = matrix[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        dist[i] = costs[from][i];
        if (dist[i] < INF) pred[i] = from;
    }
    used[from] = true;
#ifdef DBG
    cout << "The distances before the first iteration are: ";
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << "\n";
#endif // DBG
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v])) v = j;
        if (v == -1 || dist[v] == INF) break;
        used[v] = true;
        for (int j = 0; j < n; j++)
            if (costs[v][j] < INF && costs[v][j] + dist[v] < dist[j])
            {
                dist[j] = costs[v][j] + dist[v];
                pred[j] = v;
            }
#ifdef DBG
        cout << "The distances after the " << i + 1 << " iterations are: ";
        for (int j = 0; j < n; j++)
            cout << dist[j] << " ";
        cout << "\n";
    }
#endif //DBG
}
