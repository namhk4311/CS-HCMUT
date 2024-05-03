static void sortSegment(T* start, T* end, int segment_idx) {
    // TODO
    T *s = start;
    while (s < end) {
        T *iter = s;
        
        T _min = 1e9;
        T *nail = iter;
        while (iter < end) {
            if (*iter < _min) {
                nail = iter;
                _min = min(*iter, _min);
            }
            iter = iter + segment_idx;
        }
        
        //swapping
        T tmp = *nail;
        *nail = *s;
        *s = tmp;
        
        s = s + 1; 
        if (s>=end) break;
    }
}

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    for (int i = num_phases-1; i>=0; i--) {
        sortSegment(start, end, num_segment_list[i]);
        cout << num_segment_list[i] << " segments: ";
        printArray(start, end);
    }
}