template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    T val;
    Node *tmp = head;
    if (index == 0) {
        val = tmp->data;
        head = head->next;
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;
        }
        val = tmp->next->data;
        tmp->next = tmp->next->next;
        if (index == count - 1) tail = tmp;
    }
    
    --count;
    return val;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node *tmp = head;
    
    if (head->data == item) {
        head = head->next;
        --count;
        return true;
        
    }
    for (int i = 0; i < count - 1; i++) {
        if (tmp->next->data == item) {
            tmp->next = tmp->next->next;
            --count;
            if (tmp->next == NULL) tail = tmp;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (head != NULL) {
        head = head->next;
    }
    // delete[] head;
    // delete[] tail;
    head = NULL;
    tail = NULL;
    count = 0;
}

