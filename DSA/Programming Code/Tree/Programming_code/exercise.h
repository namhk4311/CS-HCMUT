#include "Tree.h"
using namespace std;
/*1.Write function count to return the number of nodes in a binary tree? The prototype of the function is as follows:

template <typename E>

int count(BNode<E> * root);

where BNode is defined in lecture slides.

Your code starts at line 40.

*/
template <typename E> 
void print(E val) {
    
}

template <typename E>

int count(BNode<E> * root){
    if (!root) return 0;
    if (root->isLeaf()) return 1;
    int l = count(root->left()), r = count(root->right());
    return 1 + l + r;
};

/*2.Write function height to return the height of a binary tree? The prototype of the function is as follows:

template <typename E>

int height(BNode<E> * root);

where BNode is defined in lecture slides.

Your code starts at line 40.*/

template <typename E>

int height(BNode<E> * root) {
    if (!root) return 0;
    if (root->isLeaf()) return 1;
    int l = height(root->left());
    int r = height(root->right());
    if (l > r) return 1 + height(root->left());
    return 1 + height(root->right());
};

/*3. Write function BSTsearch to look up a value val in the binary search tree root and return the node of the binary search tree whose value is the searching key val? This function returns NULL if there is no node whose value is val. The function also prints the value (followed by a comma) in the BST compared to the searching key val during the searching process. Your code starts at line 48. The prototype of the function is as follows:

template <typename E>

BNode<E>* BSTsearch(BNode<E> * root,E val);

where BNode is defined in lecture slides.

Your code starts at line 50.*/

template <typename E>

BNode<E>* BSTsearch(BNode<E> * root,E val) {
    if (!root) return NULL;
    if (root->element() == val) {
        cout << root->element() << ",";
        return root;
    }
    if (root->element() < val) {
        cout << root->element() << ",";
        return BSTsearch<E>(root->right(), val);
    }
    else {
        cout << root->element() << ",";
        return BSTsearch<E>(root->left(), val);
    }
};

/*4. Write function LNRtraversal to travel in LNR manner on a binary tree root to conduct function f for each traversed node? The prototype of the function is as follows:

template <typename E>

void LNRtraversal(BNode<E> * root, void (*f)(E));

where BNode is defined in lecture slides.

Your code starts at line 40.*/

template <typename E>

void LNRtraversal(BNode<E> * root, void (*f)(E)) {
    if (root != nullptr) {
        LNRtraversal(root->left(),f);
        f(root->element());
        LNRtraversal(root->right(),f);
    }
    
};

/*5. Write function BFtraversal to travel on a binary tree root in breadth-first manner to conduct function f for each traversed node? Class Queue with concrete class LQueue and class Stack with concrete class AStack have been provided for your convenience. Your code starts at line 195. The prototype of the function is as follows:

template <typename E>

void BFtraversal(BNode<E> * root, void (*f)(E));

where BNode is defined in lecture slides.

Your code starts at line 200.*/
template <typename E>

void BFtraversal(BNode<E> * root, void (*f)(E)) {
    LQueue<BNode<E>*> q;
    if (!root) return;
    q.enqueue(root);
    while (q.length()) {
        BNode<E>* head_node = q.dequeue();
        f(head_node->element());
        if (head_node->left()) {
            //f(head_node->left()->element());
            q.enqueue(head_node->left());
        }
        if (head_node->right()) {
            //f(head_node->right()->element());
            q.enqueue(head_node->right());
        }
    }
};

/*6. Write function BSTinsert to insert a new node into the binary search tree root and return the root of the binary search tree with new node added? Your code starts at line 48. The prototype of the function is as follows:

template <typename E>

BNode<E>* BSTinsert(BNode<E> * root,E val);

where BNode is defined in lecture slides.

Your code starts at line 50.*/

template <typename E>

BNode<E>* BSTinsert(BNode<E> * root,E val){
    if (!root) return new BNode<E>(val);
    BNode<E> *path = root;
    
    while (!path->isLeaf()) {
        BNode<E> *path_prev = path;
        if (val < path->element() && path->left()) path = path->left();
        else if (val >= path->element() && path->right()) path = path->right();
        if (path == path_prev) break;
    }
    if (path && val < path->element()) path->setLeft(new BNode<E>(val));
    else if (path && val >= path->element()) path->setRight(new BNode<E>(val));
    return root;
};

/*7 Write function BSTdelete to delete the first node of the binary search tree root whose value is val and return the root of the binary search tree with the node deleted? If there is no node whose value is val, the root of the current BST is returned. Your code starts at line 48. The prototype of the function is as follows:

template <typename E>

BNode<E>* BSTdelete(BNode<E> * root,E val);

where BNode is defined in lecture slides.

Your code starts at line 50.*/

template <typename E>

BNode<E>* BSTdelete(BNode<E> * root,E val){
    if (!root) return NULL;
    BNode<E> *tmp = root;
    while (tmp->element() != val && tmp) {
        if (val < tmp->element()) tmp = tmp->left();
        else tmp = tmp->right();
    }
    if (tmp->isLeaf()) {
        BNode<E> *path = root;
        while (path->left() != tmp && path->right() != tmp) {
            if (val < path->element()) path = path->left();
            else path = path->right();
        }
        if (path->left() == tmp) path->setLeft(NULL);
        else if (path->right() == tmp) path->setRight(NULL);
    }
    else {
        BNode<E> *leftmost = tmp;
        if (leftmost->right()) leftmost = leftmost->right();
        if (leftmost->left()) {
            while(leftmost->left()->left()) leftmost = leftmost->left();
            tmp->setElement(leftmost->left()->element());
            leftmost->setLeft(leftmost->left()->right());
        }
        else {
            tmp->setElement(leftmost->element());
            tmp->setRight(leftmost->right());
        }
        
    }
    return root;
};

/*8. Write function isBST to check if the binary tree root is a binary search tree or not? Note an empty binary tree is not a BST. The prototype of the function is as follows:

template <typename E>

bool isBST(BNode<E> * root);

where BNode is defined in lecture slides.

Your code starts at line 40.

*/
template <typename T> 
bool isValid(BNode<T> *root, int MIN, int MAX) {
    if (!root) return true;
    if (MIN <= root->element() && root->element() < MAX && isValid(root->left(),MIN ,root->element()) && isValid(root->right(), root->element(), MAX)) {
        return true;
    }
    return false;
}


template <typename E>

bool isBST(BNode<E> * root) {
    if (!root) return false;
    int MAXvalue = 2e9 + 7;
    return isValid<E>(root, -MAXvalue, MAXvalue);
};
