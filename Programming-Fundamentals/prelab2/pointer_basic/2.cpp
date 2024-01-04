#include <bits/stdc++.h>
using namespace std;
    
void swap(int *ptr1, int *ptr2)
{
    int tmp;
    tmp = *ptr1;
    //cout << *tmp;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

int main()
{
    int a = 5;
    int b = 6;
    swap(&a, &b);
    cout << a << ' ' << b;
    return 0;
}