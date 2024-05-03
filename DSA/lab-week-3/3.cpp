static void merge(T* start, T* middle, T* end) 
{
    
    int left_size = middle - start;
    int right_size = end - middle;
    T* temp = new T[left_size + right_size];

    
    int i = 0; 
    int j = 0; 
    int k = 0; 

    while (i < left_size && j < right_size)
    {
        if (start[i] <= middle[j])
        {
            temp[k] = start[i];
            i++;
        }
        else
        {
            temp[k] = middle[j];
            j++;
        }
        k++;
    }


    while (i < left_size)
    {
        temp[k] = start[i];
        i++;
        k++;
    }

    
    while (j < right_size)
    {
        temp[k] = middle[j];
        j++;
        k++;
    }

    
    for (int i = 0; i < left_size + right_size; i++)
    {
        start[i] = temp[i];
    }

    
    delete[] temp;
}

static void InsertionSort(T* start, T* end) 
{
    for (int i = 1; i < end - start; i++)
    {
        T key = start[i];
        int j = i - 1;
        while (j >= 0 && start[j] > key)
        {
            start[j + 1] = start[j];
            j--;
        }

        start[j + 1] = key;
    }
}
static void TimSort(T* start, T* end, int min_size) 
{
    int size = end - start;
    for (int i = 0; i < size; i += min_size)
    {
        InsertionSort(start + i, min(min_size, size - i) + start + i);
    }

    cout << "Insertion Sort: ";
    printArray(start, end);

    int i=0;
    for (int curr_size = min_size; curr_size < size; curr_size *= 2)
    {
        for (int left_start = 0; left_start < size; left_start += 2 * curr_size)
        {
            int mid = min(left_start + curr_size - 1, size - 1);
            int right_end = min(left_start + 2 * curr_size - 1, size - 1);
            merge(start + left_start, start + mid + 1, start + right_end + 1);
            cout << "Merge " << ++i<< ": ";
            printArray(start, end);
        }

    }
}