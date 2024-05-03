/*
1.
Based on class List defined on page 98 to implement a min heap used for heap sort, write function template <typename E> void reheapDown(List<E> &L, int heapsize, int startpos).

reheapDown: the element at the startpos is compared to its children and swapped with the smaller child if it is greater than the smaller child. This process is repeated until it is smaller or equal to the smaller child or it is put in the leaf.

Your code starts from line 79.
*/
template <typename E> 
void reheapDown(List<E> &L, int heapsize, int startpos){
    //cout << L.length() << " " << heapsize << endl;
    if (heapsize > L.length()) throw out_of_range("Heap size cannot be greater than the length of the list");
    if (startpos >= heapsize) return;
    // if (startpos == skip) {
    //     //reheapDown(L, heapsize, startpos + 1);
    //     return;
    // }
    L.moveToPos(startpos);
    E val1, val2;
    bool check1 = false, check2 = false;
    int pos1 = 2 * startpos + 1, pos2 = 2 * startpos + 2;
    if (pos1 < heapsize) {
        L.moveToPos(pos1);
        val1 = L.getValue(); check1 = true; 
    }
    if (pos2 < heapsize) {
        L.moveToPos(pos2);    
        val2 = L.getValue(); check2 = true;
    }
    L.moveToPos(startpos);
    if ((val1 < val2 && check1 && check2) || (check1 && !check2)) {
        if (L.getValue() <= val1) {
            //check = false;
            return;
        }
        if (val1 < L.getValue()) {
            E tmp = L.getValue();
            L.remove();
            L.insert(val1);
            L.moveToPos(pos1);
            L.remove();
            L.insert(tmp);
            if (2 * pos1 + 1 > heapsize || 2 * pos1 + 2 > heapsize) {
                //check = false; 
                return;
            }
            reheapDown(L, heapsize, 2 * startpos + 1);
        }
    }
    else if ((val1 > val2 && check1 && check2 )|| (check2 && !check1)) {
        if (L.getValue() <= val2) {
            //check = false;
            return;
        }
        if (val2 < L.getValue()) {
            E tmp = L.getValue();
            L.remove();
            L.insert(val2);
            L.moveToPos(pos2);
            L.remove();
            L.insert(tmp);
            if (2 * pos2 + 1 > L.length() || 2 * pos2 + 2 > L.length()) {
                //check = false; 
                return;
            }
            reheapDown(L, heapsize, 2 * startpos + 2);
        }
    }
    // int pos1_left = 2 * pos1 + 1, pos1_right = 2 * pos1 + 2;
    // int pos2_left = 2 * pos2 + 1, pos2_right = 2 * pos2 + 2;
}

/*
2.
Based on class List defined on page 98 to implement function  template <typename E> void makeHeap(List<E> &L) which makes the list L become a min heap. Function template <typename E> void reheapDown(List<E> &L, int heapsize, int startpos) is given for your convenience.

Your code starts from line 120.
*/

template <typename E> 
void makeHeap(List<E> &L) {
    for (int i = L.length() / 2 - 1; i >= 0; i--) {
        reheapDown(L, L.length(), i);
    }
}

/*
3.
Based on class List defined on page 98, write function template <typename E> void heapSort(List<E> &L) to sort the list L in descending order. Functions template <typename E> void makeHeap(List<E> &L) and template <typename E> void reheapDown(List<E> &L, int heapsize, int startpos) are provided for your convenience.

Your code starts from line 79.
*/

template <typename E> void heapSort(List<E> &L) {
    makeHeap(L);

    for (int i = L.length() - 1; i > 0; i--) {
        L.moveToStart();
        int heaphead = L.getValue();
        L.moveToPos(i);
        int heaptail = L.getValue();
        L.remove();
        L.insert(heaphead);
        L.moveToStart();
        L.remove();
        L.insert(heaptail);
        reheapDown(L, i, 0);
    }
}



/*
4.
Given the data structures of a binary search tree as follows:

template <typename E>

class BNode {

public:

	E key;

	BNode<E>* left;

	BNode<E>* right;

        BNode(E v,BNode<E>* l = NULL,BNode<E>* r=NULL):key(v),left(l),right(r){}

}

and 

template <typename E>

class BST {

private:

	BNode<E>* root;

public:

       BST(BNode<E> r):root(r){};

}

Write method void printGreatestSmaller(E key) for class BST to print in the greatest keys v of  a node in the BST such that v < key

Your code starts at line 24.
*/

// void printGreatestSmaller(E key) {
//     E MAX = 2e9 + 7;
//     E maxVal = -MAX;
//     if (!root) return;
//     BNode<E> *tmp = root;
//     while (tmp) {
//         if (tmp->key < key) {
//             if (maxVal < tmp->key) maxVal = tmp->key;
//             tmp = tmp->right;
//         } 
//         else tmp = tmp->left;
//     }
//     if (maxVal != -MAX) cout << maxVal;
// }

/*
5.
Write function LargestSmaller to print the largest key in the binary search tree from root travel which is smaller than the input key? The prototype of the function is as follows:

template <typename E>

void LargestSmaller(BNode<E> * root, E key);

where BNode is defined in lecture slides.

Your code starts at line 40.
*/


// template <typename T>
// void findLargest(BNode<T> *root, T key, T &maxVal) {
//     if (!root) return;
//     if (root->element() < key) {
//         if (maxVal < root->element()) maxVal = root->element();
//         return findLargest(root->right(), key, maxVal);
//     }
//     if (root->element() >= key) return findLargest(root->left(), key, maxVal);
// }


// template <typename E>
// void LargestSmaller(BNode<E> * root, E key) {
//     E MAX = 2e9 + 7;
//     E maxVal = -MAX;
//     if (!root) return;
//     findLargest(root, key, maxVal);
//     if (maxVal == -MAX) return;
//     cout << maxVal;
// };
