void topologicalSort(void (Graph::*action)(int))
{
    vector <int> indegree(nover,0);
    LQueue <int> q;
    
    for(int i = 0 ; i < nover ; i++)
    {
        Link<GEdge>*x = & srclst[i];
        while(x -> next != NULL)
        {
            indegree[x->next->element.idx]++;
            x=x->next;
            
        }
    }
    
    for (int i = 0; i < nover; ++i) {
            if (indegree[i] == 0) {
                q.enqueue(i);
            }
        }

        while (!q.isEmpty()) {
            int currentVertex = q.dequeue();
            (this->*action)(currentVertex);  

           
            Link<GEdge>* current = &(srclst[currentVertex]);
            while (current->next != nullptr) {
                int idx = current->next->element.idx;
                indegree[idx]--;
                if (indegree[idx] == 0) {
                    q.enqueue(idx);
                }
                current = current->next;
            }
        }
}