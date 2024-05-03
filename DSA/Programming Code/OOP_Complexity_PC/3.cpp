#include <bits/stdc++.h>
using namespace std;

unsigned int fibo(int n) {
    unsigned int a = 0, b = 1;
    if (n == 1) return 1; 
    for (int i = 3; i <= n; i++) {
        unsigned int tmp = a;
        a = a + b;
        b = tmp;
    }
    return a;
} 

int main()
{
   
    return 0;
}