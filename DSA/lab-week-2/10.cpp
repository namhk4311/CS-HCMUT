void bfs(vector<vector<int>> graph, int start) {
	int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;

    // Enqueue the start node and mark it as visited
    q.push(start);
    visited[start] = true;


    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Visit all adjacent nodes of the current node
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}