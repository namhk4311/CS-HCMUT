#include <iostream>
#include <list>
#include <queue>
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
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        bool visited[this->V];
        //cout << this->V;
        for (int i = 0; i < this->V; i++) visited[i] = false;
        visited[v] = true;
        //int sizeV = this->V;
        queue<int> q;
        Adjacency *bfsorder = new Adjacency(this->V);
        //bfsorder[v] = adj[v];
        q.push(v);
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            bfsorder->push(s);
            for (int i = 0; i < adj[s].getSize(); i++) {
                int x = adj[s].getElement(i);
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return bfsorder;
        
	}
};