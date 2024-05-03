#include "2.h"

int Fib(int n) {
    if (n == 0) return 1;
    AStack<int> top;
    top.push(1);
    top.push(1);
    n--;
    while (n--) {
        int b = top.pop();
        int a = top.pop();
        top.push(b);
        top.push(a + b);
    }
    return top.topValue();
}

int main() {
    cout << Fib(4);
}