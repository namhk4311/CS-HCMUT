#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int>> adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int>>(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	
	
	bool dfs(int v, bool* visted, int e){
	    int i  = v;
	    if(visted[i] == false){
	        visted[i] = true;
	        bool check = false;
	        for(int i : adj[i])
	        {
	            check =  check || dfs(i, visted, e);
	             if(check) break;
	        }
	        return check;
	    }
	    else if(v == e) return true;
	    return false;
	}
	
	
	bool isCyclic()
	{
	    // Student answer
	    for(int i = 0; i < V; i++){
    	    bool visted[V] = {false};
    	    if(dfs(i,visted, i)) return true;
	    }
	    return false;
	    
	}
}; 

void implement() {
    DirectedGraph g(8);
    int edege[][2] = {{0,6}, {1,2}, {1,4}, {1,6}, {3,0}, {3,4}, {5,1}, {7,0}, {7,1}};

    for(int i = 0; i < 9; i++)
    \tg.addEdge(edege[i][0], edege[i][1]);

    if(g.isCyclic())
    \tcout << "Graph contains cycle";
    else
    \tcout << "Graph doesn't contain cycle";
}