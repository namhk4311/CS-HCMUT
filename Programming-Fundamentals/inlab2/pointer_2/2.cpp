#include <bits/stdc++.h>
using namespace std;

void addElement(int*& arr, int n, int val, int index) {
    int *tmp = new int [n + 1];
    for (int i = 0; i < n; i++){
        tmp[i] = arr[i];
    }
    tmp[n] = val;
    arr = new int [n + 1];
    for (int i = 0; i < n + 1; i++){
        arr[i] = tmp[i];
    }
} 

int main()
{
    // int n = 2;
    // int *arr = {2, 3};
    // int val = 1, index = 1;
    // addElement(arr, n, val, index);

    return 0;
}