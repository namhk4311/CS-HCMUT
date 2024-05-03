#include <bits/stdc++.h>
using namespace std;

int moves = 0, comps = 0, swap_time = 0;

void printArray(int* arr, const int &n) {
    cout << "arr = [";
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n - 1] << "]\n";
}

void print() {
    cout << "Total moves: " << moves << '\n';
    cout << "Total compares: " << comps << '\n';
    cout << "------------------\n";
    moves = 0, comps = 0;
}

int partition(int *key, int left, int right, int pivot) {
    do {
        while (key[++left] < pivot);
        while ((left < right) && key[--right] >= pivot);
        swap(key[left], key[right]); swap_time++;
    } while (left < right);
    return left;
}

void qsort(int *arr, int i, int j) {
    if (j <= i) return;
    int pivotindex = i + (j - i) / 2;
    swap(arr[pivotindex], arr[j]); swap_time++;
    int k = partition(arr, i - 1, j, arr[j]);
    swap(arr[k], arr[j]); swap_time++;
    qsort(arr, i, k - 1);
    qsort(arr, k + 1, j);
}
int count_val = 0;
void bubblesort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                ++count_val;
            }
        }
    }
}

int main()
{
    int n = 10;
    int* arr = new int[n] {22, 67, 13, 99, 4, 35, 44, 64, 17, 18};
    cout << "before sort: ";
    printArray(arr, n);
    //cout << endl;
    qsort(arr, 0, n - 1);
    //bubblesort(arr, n);
    cout << "after sort: ";
    printArray(arr, n);
    cout  << count_val;
    return 0;
}