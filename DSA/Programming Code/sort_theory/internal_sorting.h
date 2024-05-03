template <typename E>
void swapVal(E &a, E &b) {
    E tmp = a;
    a = b;
    b = tmp;
}

//insertion sort
template<typename E>
void inssort(E A[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        E tmp = A[i];
        for (j = i - 1; (j >= 0) && tmp < A[j]; j--) {
            A[j + 1] = A[j];
        } 
        A[j + 1] = tmp;
        // std::cout << "Step " << i << "(" << tmp << ")" <<  ": ";
        // for (int k = 0; k < n; k++) std::cout << A[k] << " ";
        // std::cout << std::endl;
    }
}
//time complexity: theta(n^2)

//selection sort
template <typename E>
void selsort(E A[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        E lowindex = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[lowindex]) lowindex = j;
        }
        swapVal<E>(A[i], A[lowindex]);       
        std::cout << "Step " << i + 1 <<  ": ";
        for (int k = 0; k < n; k++) std::cout << A[k] << " ";
        std::cout << std::endl;
    }
}

//bubble sort
template <typename E>
void bubsort(E A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (A[j] < A[j - 1]) swapVal(A[j], A[j - 1]);
        }
        // std::cout << "Step " << i + 1 <<  ": ";
        // for (int k = 0; k < n; k++) std::cout << A[k] << " ";
        // std::cout << std::endl;
    }
}

//shell sort (O(n^1.25))
// template <typename E>
// void segmentSort(E data[], int segment, int k, int size) { //similar to insertion sort
//     int current, walker;
//     for (current = segment + k; current < size; current += k) { //element from the first of the i-th segment to the last of i-th segment;
//         E tmp = data[current];
//         for (walker = current - k; walker >= 0 && tmp < data[walker]; walker -= k) {
//             data[walker + k] = data[walker];
//         }
//         data[walker + k] = tmp;
//     }
// }

// template <typename E>
// void shellSort(E data[], int n) {
//     for (int k = n / 2; k > 2; k /= 2) {
//         for (int segment = 0; segment < k; segment++) {
//             std::cout << n << std::endl;
//             segmentSort<E>(data, segment , k, n);
//         }
//         // std::cout << "Step " << k + 1 <<  ": ";
//         for (int t = 0; t < n; t++) std::cout << data[t] << " ";
//         std::cout << std::endl;
//     }
    
// }

template <typename E> void inssort2(E A[], int n, int incr) {
    for (int i = incr; i < n; i += incr) {
        for (int j = i; j >= incr && A[j] < A[j - incr]; j -= incr) {
            swapVal<E>(A[j], A[j - incr]);
        }
    }
}

template <typename E> void shellSort(E A[], int n) {
    for (int i = n / 2; i > 2; i /= 2) {
        for (int j = 0; j < i; j++) {
            inssort2<E>(&A[j], n - j, i);
        }
    }
    inssort2<E>(A, n, 1);
}

//heap sort




