template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    T *s = start;
    while (s != end) {
        T *iter = s;
        
        T _min = 1e9;
        T *nail = iter;
        while (iter!=end) {
            if (*iter < _min) {
                nail = iter;
                _min = min(*iter, _min);
            }
            iter++;
        }
        
        T tmp = *nail;
        *nail = *s;
        *s = tmp;
        
        s++; 
        if (s==end) break;
        printArray(start, end);
    }
}