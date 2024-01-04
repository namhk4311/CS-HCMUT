#include <bits/stdc++.h>
using namespace std;

int getValueAtIndex(int *ptr, int k)
{
    int *res;
    res = ptr + k;
    return *res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k = 3;
    cout << getValueAtIndex(arr, k);    
    return 0;
}