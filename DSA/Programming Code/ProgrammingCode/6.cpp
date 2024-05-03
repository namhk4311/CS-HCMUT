#include <bits/stdc++.h>
using namespace std;
    
typedef struct Item* ptr;

struct Item {
    double coef; // coefficient
    int exp; // exponent
    ptr next;
};

ptr makeNode(double x, int y) {
    ptr tmp = new Item();
    tmp->coef = x;
    tmp->exp = y;
    tmp->next = NULL;
    return tmp;
}

void push(ptr &a, double x, int y) {
    ptr tmp = makeNode(x, y);
    if (a == NULL) {
        a = tmp;
    }
    else {
        tmp->next = a;
        a = tmp;
    }
}

ptr inputPolynomial() {
    double coef; int exp;
    ptr head = NULL;
    while (1) {
        cin >> coef >> exp;
        if (coef == 0) break;
        push(head, coef, exp);
    }
    return head;
}
    
int main()
{
   
    return 0;
}