/*
Implement the function void shallowCopy(int*& newArr, int*& arr) that can create a copy from a one-dimensional array.

Input:  The one-dimensional array that needs to be copied.
Output: The destination array.
Note: After finishing execution, both the one-dimensional array that needs to be copied and the destination array use the same data memory.
*/

#include <bits/stdc++.h>
using namespace std;

void shallowCopy(int*& newArr, int*& arr) {
    newArr = arr;
}

int main()
{
    int* arr = new int[2];
    arr[0] = 2; arr[1] = 3;
    int* newArr = nullptr;
    shallowCopy(newArr, arr);
    cout << newArr[0] << ' ' << newArr[1];
    delete[] arr;
    return 0;
}