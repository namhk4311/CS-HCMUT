// Simple binary tree node implementation
#include "Tree.h"
#include "dictionary.h"

template <typename Key, typename E>
class BSTNode : public BinNode<E> {
    private:
        Key k; // The node’s key
        E it; // The node’s value
        BSTNode* lc; // Pointer to left child
        BSTNode* rc; // Pointer to right child
    public:
        // Two constructors -- with and without initial values
        BSTNode() { lc = rc = NULL; }
        BSTNode(Key K, E e, BSTNode* l =NULL, BSTNode* r =NULL)
        { k = K; it = e; lc = l; rc = r; }
        ~BSTNode() {} // Destructor
        // Functions to set and return the value and key
        E& element() { return it; }
        void setElement(const E& e) { it = e; }
        Key& key() { return k; }
        void setKey(const Key& K) { k = K; }
        // Functions to set and return the children
        inline BSTNode* left() const { return lc; }
        void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
        inline BSTNode* right() const { return rc; }
        void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }
        // Return true if it is a leaf, false otherwise
        bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};

template <typename Key, typename E>
class BST : public Dictionary<Key, E> {
    private:
        BSTNode<Key, E> *root;
        int nodecount;
        void clearhelp(BSTNode<Key, E> *root) {
            if (root == nullptr) return;
            clearhelp(root->left());
            clearhelp(root->right());
            delete root;
        };
        BSTNode<Key, E> *inserthelp(BST<Key, E> *root, const Key& k, const E& it) {
            if (!root) return new BSTNode<Key, E>(k, it, nullptr, nullptr);
            if (k < root->key()) root->setLeft(inserthelp(root->left(), k, it));
            else root->setRight(root->right(), k, it);
            return root; 
        };
        BSTNode<Key, E> *deletemin(BSTNode<Key, E> *) {};
        BSTNode<Key, E> *getmin(BSTNode<Key, E> *);
        BSTNode<Key, E> *removehelp(BST<Key, E> *, const Key&);
        E findhelp(BSTNode<Key, E> *, const Key&) const;
        void printhelp(BSTNode<Key, E> *, int) const;
    public:
        BST() {root = NULL; nodecount = 0;}
        ~BST() {clearhelp(root);}
        void clear() {
            clearhelp(root);
            root = NULL;
            nodecount = 0;
        }
        void insert(const Key& k, const E& e) {
            root = inserthelp(root, k, e);
        }
        E remove(const Key& k) {
            E temp = findhelp(root, k);
            if (temp != NULL) {
                root = removehelp(root, k);
                nodecount--;
            } 
            return temp;
        } 
        E removeAny() {
            if (root) {
                E temp = root->element();
                root = removehelp(root, root->key());
                nodecount--;
                return temp;
            }
            else return NULL;
        }
        E find(const Key& k) const {
            return findhelp(root, k);
        }
        int size() {
            return nodecount;
        }
        void print() {
            if (root == nullptr) cout  << "The BST is empty.\n";
            else printhelp(root, 0);
        }
};
