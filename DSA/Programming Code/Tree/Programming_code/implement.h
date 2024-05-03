#include "exercise.h"

void ex1() { //result 3
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));
    cout<<count(btree);
}


void ex2() {
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));  
    cout<<height(btree);
}

void ex3() {
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));
    cout << (BSTsearch(btree,2)!= NULL);
}


void ex4() {
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));
    LNRtraversal(btree,print);
}

void ex5() {
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));
    BFtraversal(btree,print);
}

void ex6() {
    BNode<int>*res;
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));
    res = BSTinsert(btree,2);
}

void ex7() {
    BNode<int>*res;
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));
    res= BSTdelete(btree,3);
}

void ex8() {
    BNode<int>* btree = new BNode<int>(4,new BNode<int>(3),new BNode<int>(5));
    cout<<isBST(btree);
}
