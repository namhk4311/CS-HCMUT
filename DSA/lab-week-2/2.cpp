template<class T>
T DLinkedList<T>::get(int index) {
    if(count==1){
        return head->data;
    }
    Node* temp= head;
    int check=0;
    while(check!=index){
        temp=temp->next;
        check++;
    }
    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
     if(index==0){
        head->data=e;
    }
    Node* temp= head;
    int check=0;
    while(check!=index){
        temp=temp->next;
        check++;
    }
    temp->data=e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */

    if(count>0){
        return false;
    }
    return true;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* temp=head;
    for(int i=0;i<count;i++){
       
        if(temp->data==item){
            return i;
        }
         temp=temp->next;
    }
    return -1;
    
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    Node* temp=head;
    for(int i=0;i<count;i++){
        if(temp->data==item){
            return true;
        }
        temp=temp->next;
    }
    return false;
    
}