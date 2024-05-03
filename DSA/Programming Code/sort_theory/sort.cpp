#include <iostream>
#include "internal_sorting.h"
#include "external_sorting.h"
using namespace std;
    
int main()
{
    int a[] = {3, 6, 4, 1, -11};
    int tmp[sizeof(a) / sizeof(int)];
    shellSort<int>(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) cout << a[i] << " ";
    return 0;
}