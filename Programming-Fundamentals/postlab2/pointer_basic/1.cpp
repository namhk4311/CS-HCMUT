#include <iostream>
using namespace std;

int findMax(int *ptr, int n)
{
    if(n==0){
        return 0;
    }
    return max(findMax(ptr,n-1),*(ptr++));
}

int main()
{
    int a[] = {1,2,3,4,5};
    cout << findMax(a,5);
    return 0;
}