//1.h

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	void dfs(int v, Adjacency* result, bool* visited){
	    if(visited[v] == false){
	        visited[v] = true;
	       result->push(v);
          for(int i = 0 ; i < adj[v].getSize(); i++){
                int tmp = adj[v].getElement(i);
                dfs(tmp, result, visited);
                 visited[tmp] = true;
            }	        
	    }
	}
	
	Adjacency *DFS(int v)
    {
        bool visited[V] = {false};
        Adjacency* result = new Adjacency();
    
        dfs(v, result, visited);
        
        return result;
        
	}
};

void implement() {
    int V = 8, visited = 0;

    Graph g(V);
    Adjacency *arr;
    int edge[][2] = {{0,1}, {0,2}, {0,3}, {0,4}, {1,2}, {2,5}, {2,6}, {4,6}, {6,7}};
    for(int i = 0; i < 9; i++)
    {
    \tg.addEdge(edge[i][0], edge[i][1]);
    }

    // g.printGraph();
    // cout << endl;
    arr = g.DFS(visited);
    arr->printArray();
    delete arr;
}