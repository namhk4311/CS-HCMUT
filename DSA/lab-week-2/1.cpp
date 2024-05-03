template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newnode= new Node(e);
    if(count==0){
        head=tail=newnode;
        count++;
        return;
    }
    
    newnode->previous=tail;
    tail->next=newnode;
    tail=newnode;
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    Node* newnode= new Node(e);
    if(index==0){
            if(count==0){
            head=tail=newnode;
            count++;
            return;
        }
        newnode->next=head;
        head->previous=newnode;
        head=newnode;
        count++;
        return;
    }
    Node* check= head;
    int num=0;
    while(num!=index&&check!=nullptr){
        check=check->next;
        num++;
    }
    if(check==nullptr){
        tail->next=newnode;
        newnode->previous=tail;
        tail=newnode;
        count++;
        return;
    }
    newnode->previous=check->previous;
    check->previous->next= newnode;
    check->previous=newnode;
    newnode->next=check;
    count++;
}

template<class T>
int DLinkedList<T>::size() {
    
    return count;
    return 0;
}