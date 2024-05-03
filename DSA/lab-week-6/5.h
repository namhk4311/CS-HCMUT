/*
Given a graph and a source vertex in the graph, find shortest paths from source to destination vertice in the given graph using Dijsktra's algorithm.

Following libraries are included: iostream, vector, algorithm, climits, queue
*/

int Dijkstra(int** graph, int src, int dst)
{
    int n = 0;
    int **tmp = graph;
    while (tmp[n]) {
        n++;
    }
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dst];
}

void implement() {
    int n = 6;
    int init[6][6] = {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 0, 50, 10, 0},
        {20, 0, 0, 20, 33, 0},
        {0, 50, 20, 0, 20, 2},
        {0, 10, 33, 20, 0, 1},
        {0, 0, 0, 2, 1, 0} };

    int** graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = init[i];
    }

    cout << Dijkstra(graph, 0, 1);
}