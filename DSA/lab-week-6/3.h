/*
Given a graph represented by an adjacency-list edges.

Request: Implement function:

int connectedComponents(vector<vector<int>>& edges);
Where edges is the adjacency-list representing the graph (this list has between 0 and 1000 lists). This function returns the number of connected components of the graph.

Example:

Given a adjacency-list: [[1], [0, 2], [1], [4], [3], []]

There are 3 connected components: [0, 1, 2], [3, 4], [5]

Note:

In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.
*/

void bfs(bool *visited, int u, vector<vector<int>> edges){
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();
       // cout << v << " ";
        for (int x: edges[v]){
            if (!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}


int connectedComponents(vector<vector<int>>& edges) {
    // STUDENT ANSWER
    int ans = 0;
    int size = edges.size();// cout << size << endl;
    bool visited[size];
    for (int i = 0; i < size; i++) visited[i] = false;
    for (int i = 0; i < size; i++) {
            
            if (!edges[i].size()) {
                ans++;
                continue;
            }
            int start = i;
            if (!visited[start]) {
                ++ans;
                bfs(visited , start, edges);
               // cout << endl;
            }
        
    }
    return ans;
}

void implement() {
    vector<vector<int>> graph {
    \t{1},
    \t{0, 2},
    \t{1, 3},
    \t{2},
    \t{}
    };
    cout << connectedComponents(graph);
}