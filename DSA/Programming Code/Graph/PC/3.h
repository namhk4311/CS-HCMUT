#include "main.h"
#include "link.h"
#include <queue>
class GEdge {
public:
      int idx; // index of the destination vertex of the edge

      int weight; // weight of the edge

      GEdge(int l,int w): idx(l),weight(w){}

};

struct edge {

     string src,dst;//labels of source and destination of the directed edge

     int weight;// weight of the edge

};

class Graph {

   private:

         int nover;

         string * labels;

         Link<GEdge>* srclst; // list of source vertex of edges

   public:

        Graph(string vertices[], int n):nover(n),labels(vertices) {

                srclst = new Link<GEdge>[n];

        }
        void BFS(string startlabel,void (Graph::*action)(int)) {
            bool visited[nover];
            for (int i = 0; i < nover; i++) visited[i] = false;
            queue<int> q;
            int startIdx;
            for (int i = 0; i < nover; i++) {
                if (labels[i] == startlabel) {startIdx = i; break;}
            }
            q.push(startIdx); visited[startIdx] = true;
            while (!q.empty()) {
                
                int currentIdx = q.front();
                q.pop();
                
                (this->*action)(currentIdx);
                Link<GEdge> *curr = &srclst[currentIdx];
                while (curr->next) {
                    if (!visited[curr->next->element.idx]) {
                        q.push(curr->next->element.idx);
                        visited[curr->next->element.idx] = true;
                    }
                    curr = curr->next;
                }
            }
        }
};

