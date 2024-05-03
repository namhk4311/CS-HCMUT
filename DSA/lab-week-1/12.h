template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if (index < 0 || index > count) throw std::out_of_range("index is out of range");
    T tmp = data[index];
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    count--;
    return tmp;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
    /* Remove the first apperance of item in array and return true, otherwise return false */
    int index = 0;
    if (data[index] == item) {
        for (int i = 0; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
        return true;
    }
    while (data[index] != item && index < count) {
        index++;
    }
    if (index == count) return false;
    for (int i = index; i < count - 1; i++) data[i] = data[i + 1];
    count--;
    return true;
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    if (data) {
        delete[] data;
    }
    data = new T[5];
    count = 0;
    capacity = 5;
}
