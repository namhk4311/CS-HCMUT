#include <bits/stdc++.h>
using namespace std;

typedef struct Item* ptr;

struct Item
{
    int value;
    ptr next;
};

ptr makeNode(int x) {
    ptr tmp = new Item();
    tmp->value = x;
    tmp->next = NULL;
    return tmp;
}

void push(ptr &top, int x) {
    ptr tmp = makeNode(x);
    if (top == NULL) {
        top = tmp;
    }
    else {
        tmp->next = top;
        top = tmp;
    }
}

ptr inputList() {
    int inp;
    ptr list = NULL;
    while (1) {
        cin >> inp;
        if (inp >= 0) {
            push(list, inp);
        }
        else break;
    }
    return list;
}

int main()
{
   
    return 0;
}