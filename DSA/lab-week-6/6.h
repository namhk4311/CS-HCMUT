/*
implement topologicalSort function on a graph. (Ref here)
https://www.geeksforgeeks.org/topological-sorting/
void topologicalSort();
where Adjacency is a structure to store list of number. Note that, the vertex index starts from 0. To match the given answer, please always traverse from 0 when performing the sorting.
*/

#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};

class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    //Heling functions
    
    void topologicalSort_1(int v, bool visited[], list<int>& stack){
         visited[v] = true;

        for(int i = 0; i < adj[v].getSize(); i++){
            int tmp = adj[v].getElement(i);
            if (!visited[tmp])
                topologicalSort_1(tmp, visited, stack);
        }
     
        stack.push_back(v);       
    }

    void topologicalSort(){
        //TODO
         list<int> stack;
     
        bool* visited = new bool[V];
        
        for (int i = 0; i < V; i++)
            visited[i] = false;
     
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSort_1(i, visited, stack);
     
        // Print contents of stack
        while (stack.empty() == false) {
            cout << stack.back() << " ";
            stack.pop_back();
        }
    }
};

void implement() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

}
