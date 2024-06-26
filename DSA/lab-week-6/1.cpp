#include <bits/stdc++.h>
#include "1.h"
using namespace std;
    


int main()
{
    int V = 6;
    int visited = 0;

    Graph g(V);
    Adjacency* arr = new Adjacency(V);
    int edge[][2] = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,4},{3,5},{4,5}};

    for(int i = 0; i < 8; i++)
    {
        g.addEdge(edge[i][0], edge[i][1]);
    }

    arr = g.BFS(visited);
    arr->printArray();
    delete arr;
    return 0;
}