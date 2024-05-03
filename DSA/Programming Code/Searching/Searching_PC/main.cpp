#include "main.h"
#include "searching_funct.h"

void ex1() {
    int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
    cout << binarysearch(arr,0,22,75);
}

void ex2() {
    int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
    cout<<binarysearch(arr,23,75);
}

void ex3() {
    int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
    cout<<dictionarySearch(arr,0,22,38);
}

void ex4() {
    int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
    cout<<jumpsearch(arr,23,75,5);
}

void ex5() {
    ChainingHash* hashTable = new ChainingHash(11, hashWith11);
    int data[] = {28, 81, 55, 92, 33, 29, 18, 23, 40, 99, 79, 74, 49, 64, 17};
    int size = sizeof(data)/ sizeof(int);
    for (int i = 0; i < size; i++) {
        hashTable->insert(data[i]);
    }

    int indices[] = { 1, 5, 7 };
    int indicesSize = sizeof(indices)/ sizeof(int);
    for (int i = 0; i < indicesSize; i++) {
        hashTable->remove(data[indices[i]]);
    }


    hashTable->dump();
}

void catchexception_ex5() {
    ChainingHash* hashTable = new ChainingHash();
}

int main() {
    try {
        ex1();
        catchexception_ex5();
    }
    catch(const char *e) {
        cout << e;
    }
    
}   