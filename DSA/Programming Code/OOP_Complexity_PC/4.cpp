#include <bits/stdc++.h>
using namespace std;
    
template <typename T>
int findMax(T arr[],int n){
    T max_val = arr[0];
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (max_val < arr[i]) {
            max_val = arr[i];
            max_idx = i;
        }
    }
    return max_idx;
}

int main()
{
   
    return 0;
}