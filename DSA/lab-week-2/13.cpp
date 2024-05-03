template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (count <= 1) return;
    
    Node* iter = tail;
    Node* curr = NULL;
    
    while (iter != head) {
        curr = head;
        bool swap = 0;
        while (curr != iter) {
            //swapping
            if (curr->next->data < curr->data) {
                swap = 1;
                int tmp = curr->next->data;
                curr->next->data = curr->data;
                curr->data = tmp;
            }
            curr = curr->next;
        }
        
        if (!swap) break;
        
        Node* nail = iter;
        iter = head;
        while (iter->next != nail) iter = iter->next;
    
        this->printList();
    }
}