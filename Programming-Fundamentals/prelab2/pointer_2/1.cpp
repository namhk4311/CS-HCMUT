/*
Implement the function  int* zeros(int n) which can create an array with n zero element.

Input: The array size n.
Output: The pointer that points to the allocated array.
Note: In the case of failed allocation, the function will return nullptr value.
*/

#include <bits/stdc++.h>
using namespace std;
    
int* zeros(int n) {
    if (n <= 0){
        return nullptr;}
    int *array = new int[n]();
    return array;
    delete [] array;
}

int main()
{
    int n; cin >> n;
    cout << *zeros(n);
    return 0;
}