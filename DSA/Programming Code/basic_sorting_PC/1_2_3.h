//1
template <typename E> void bubbleSort(List<E> &L) {
    int n = L.length();
    for (int i = 0; i < n - 1; i++) {
        L.moveToPos(n - 1);
        for (int j = n - 1; j > i; j--) {
            E val1 = L.getValue();
            L.prev();
            E val2 = L.getValue();
            if (val1 < val2) {
                L.next();
                L.remove();
                L.insert(val2);
                L.prev();
                L.remove();
                L.insert(val1);
            }
        }
    }
}

template <typename E> void insertionSort(List<E> &L) {
    int n = L.length();
    if (n == 1) return;
    
    int i, j;
    for (i = 1; i < n; i++) {
        L.moveToPos(i);
        E tmp1 = L.getValue();
        L.prev();
        for (j = i - 1; (j >= 0) && (tmp1 < L.getValue()); j--) {
            E tmp2 = L.getValue();
            L.next();
            L.remove();
            L.insert(tmp2);
            L.prev();
            if(j != 0) L.prev();
        }
        if (j >= 0) L.next();
        L.remove();
        L.insert(tmp1);
    }
}

template <typename E> void selectionSort(List<E> &L) {
    int n = L.length();
    if (n == 1) return;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        L.moveToPos(i);
        int lowindex = i;
        E tmp1 = L.getValue();
        L.next();
        for (j = i + 1; j < n; j++) {
            if (L.getValue() < tmp1) {
                lowindex = j;
                tmp1 = L.getValue();
            }
            L.next();
        }
        if (lowindex != i) {
            L.moveToPos(i);
            E tmp2 = L.getValue();
            L.remove();
            L.insert(tmp1);
            L.moveToPos(lowindex);
            L.remove();
            L.insert(tmp2);
        }
    }
}