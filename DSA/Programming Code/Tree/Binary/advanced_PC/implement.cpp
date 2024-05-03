#include "main.h"
#include "List.h"
#include "Link.h"
#include "Tree.h"
#include "exercise.h"

template <typename E>
void printAll(List<E>& L) {
    cout << "{";
    for (int i = 0; i < L.length(); i++) {
        L.moveToPos(i);
        cout << L.getValue();
        if (i != L.length() - 1) cout << ", "; 
    }
    cout << "}";
}

void ex3() {
    LList<int> x;
    x.append(20);
    x.append(15);
    x.append(10);
    x.append(25);
    x.append(1);
    x.append(2);
    x.append(100);
    x.append(23);
    heapSort(x);
    printAll(x);
}

int main() {
    ex3();
}

