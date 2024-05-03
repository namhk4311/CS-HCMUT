//Divide-and-conquer meta algorithum

using namespace std;
//Merge-sort
template<typename E>
void mergesort(E A[], E tmp[], int left, int right) {
    if (left == right) return;
    int mid = (left + right) / 2;
    mergesort<E>(A, tmp, left, mid);
    mergesort<E>(A, tmp, mid + 1, right);
    for (int i = left; i <= right; i++) {
        tmp[i] = A[i];
    }
    int i1 = left, i2 = mid + 1;
    for (int curr = left; curr <= right; curr++) {
        if (left == mid + 1) {
            A[curr] = tmp[i2++];
        }
        else if (i2 > right) A[curr] = tmp[i1++];
        else if (tmp[i1] <= tmp[i2]) A[curr] = tmp[i1++];
        else A[curr] = tmp[i2++];
    }
    // cout << "A: ";
    // for (int i = 0; i < right; i++) cout << A[i] << " ";
    // cout << endl;
    // cout << "tmp: ";
    // for (int i = 0; i < right; i++) cout << tmp[i] << " ";
    // cout << endl;
}