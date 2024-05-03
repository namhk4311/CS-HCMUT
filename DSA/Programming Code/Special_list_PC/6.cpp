#include "2.h"
using namespace std;

template <typename E> 
void reverse(E* L, int n) {
    Stack<E> *S = new AStack<E>();
    for (int i = 0; i < n; i++) S->push(L[i]);
    for (int i = 0; i < n; i++) {
        L[i] = S->pop();
    }
}

int main()
{
    int x[] = {3,1,2,4};
    reverse<int>(x,4);
    //print<int>(x,4);
    for (int i = 0; i < 4; i++) cout << x[i] << " ";
    return 0;
}