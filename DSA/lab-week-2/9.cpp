bool isBipartite(vector<vector<int>> graph) {
  int n = graph.size();
    vector<int> color(n, -1); 
    queue<int> q;

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
   
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (color[neighbor] == -1) {
                     
                        color[neighbor] = 1 - color[curr];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                   
                        return false;
                    }
                }
            }
        }
    }

    return true;
}