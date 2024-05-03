template <class T>
T DLinkedList<T>::removeAt(int index)
{
    if(count==1&& index==0){
         T datacheck=head->data;
        Node* temp=head;
        delete temp;
        count--;
        return datacheck;
        
    }
    /* Remove element at index and return removed value */
    if(index==count-1){
        Node* temp=tail;
        T datacheck=tail->data;
        tail=tail->previous;
        tail->next=nullptr;
        count--;
        delete temp;
        return datacheck;
    }
    else if(index==0){
        T datacheck=head->data;
        Node* temp=head;
        
            head=head->next;
            head->previous=nullptr;
            delete temp;
            count--;
            return datacheck;
        
    }
    Node* temp=head;
    for(int i=0;i<index;i++){
        temp=temp->next;
    }
    T datacheck=temp->data;

    temp->previous->next=temp->next;
    temp->next->previous=temp->previous;
    count--;
    delete temp;
    return datacheck;
  
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
     Node* temp=head;
     int size=count;
    /* Remove the first apperance of item in list and return true, otherwise return false */
    for(int i=0;i<size;i++){
        
        if(temp->data==item){
            if(count==1){
                Node* temp=head;
                delete temp;
                count--;
                return true;
            }
            if(i==0){
                head=head->next;
                head->previous=nullptr;
                delete temp;
                count--;
                return true;
            }
            else if(i==count-1){
                tail=tail->previous;
                tail->next=nullptr;
                count--;
                delete temp;
                return true;
            }
            temp->previous->next=temp->next;
            temp->next->previous=temp->previous;
            count--;
            delete temp;
            return true;
        }
        temp=temp->next;
        
    }
    return false;
    
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    for(int i=0;i<count;i++){
        Node* temp=head;
        head=head->next;
        
        delete temp;
    }
    head=nullptr;
    tail=nullptr;
    count=0;
}
