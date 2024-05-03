#include "main.h"

struct edge {

     string src,dst;//labels of source and destination of the directed edge

     int weight;// weight of the edge

};

class Graph {

   private:

         int nover;

         string* labels;

         int** wm; // weight matrix

   public:

        Graph(string vertices[], const int n): nover(n),labels(vertices) {
               wm = new int*[n];
               for (int i = 0; i < n; i++) {
                    wm[i] = new int[i];
               }
                for (int i = 0; i < n; i++) 
                     for (int j = 0; j < n; j++) 
                         if (i == j) wm[i][i] = 0; else wm[i][j] = INT_MAX;

        }

       void addEdge(struct edge edges[],int n) { 
            for (int i = 0; i < n; i++) {
                int x = edges[i].src[0] - 97;
                int y = edges[i].dst[0] - 97;
                wm[x][y] = edges[i].weight;
                wm[y][x] = edges[i].weight;
            }
        }
        void printGraph() {
               for (int i = 0; i < nover; i++) {
                    for (int j = 0;  j < nover; j++) {
                         if (wm[i][j] == INT_MAX) continue;
                         if (i == j) continue;
                         else {
                              cout << "from " << labels[i] << " to " << labels[j] << " weight " << wm[i][j] << endl;
                         }
                    }
               } 
        }
};