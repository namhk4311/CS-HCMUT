#include "main.h"
#include "link.h"
class GEdge {
public:
    string label; // label of the destination vertex of the edge

    int weight; // weight of the edge

    GEdge(string l,int w) { label=l;weight=w;}

};

struct edge {
     string ver1,ver2;//labels of vertices of the edge
     int weight;// weight of the edge
};

class Graph {

   private:

         int nover;

         Link<GEdge>* srclst; // list of source vertex of edges

   public:

        Graph(string vertices[], int n):nover(n) {

                srclst = new Link<GEdge>[n];

                for (int i = 0; i < n; i++) srclst[i].element.label = vertices[i];

        }

       void addEdge(struct edge edges[],int n) { 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < nover; j++) {
                    if (srclst[j].element.label == edges[i].ver1) {
                        Link<GEdge> *curr = &srclst[j];
                        while (curr->next != nullptr && curr->next->element.label < edges[i].ver2) curr = curr->next;
                        curr->next = new Link<GEdge>(GEdge(edges[i].ver2, edges[i].weight), curr->next);
                    }
                    if (srclst[j].element.label == edges[i].ver2) {
                        Link<GEdge> *curr = &srclst[j];
                        while (curr->next != nullptr && curr->next->element.label < edges[i].ver1) curr = curr->next;
                        curr->next = new Link<GEdge>(GEdge(edges[i].ver1, edges[i].weight), curr->next);
                    }
                }
            }
        }
};