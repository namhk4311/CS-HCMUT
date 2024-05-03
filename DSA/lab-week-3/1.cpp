static T* Partition(T* start, T* end) {
    T * arr = start;
    int low = 0, high = end - start - 1;
    int pivot = arr[low];
    int i = low, j = high + 1;
 
    do {
        do {
            i++;
        } while (arr[i] < pivot);
 
        do {
            j--;
        } while (arr[j] > pivot);
 
        if (i >= j){
            break;
        }
 
        swap(arr[i], arr[j]);
    }   while(i <= j);

    if(i <= j) swap(arr[i], arr[j]);
    swap(arr[low], arr[j]);
    cout << j << " ";
    return start + j;
    
}

static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if(start < end){
        T* privot = Partition(start, end);
        QuickSort(start, privot);
        QuickSort(privot+1,end);
    }
}