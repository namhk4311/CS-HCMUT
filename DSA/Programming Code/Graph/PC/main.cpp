#include "1.h"
using namespace std;
    
void ex1() {
    string x[] = {"a", "b", "c", "d"};
    edge t[] = {{"a","b",4},{"b","c",2},{"a","c",3},{"b","d",6},{"c","a",3},{"c","d",5}};
    Graph * g = new Graph(x,4);
    g->addEdge(t,5);
    g->printGraph();
    delete g;
}

int main()
{
    ex1();
    return 0;
}