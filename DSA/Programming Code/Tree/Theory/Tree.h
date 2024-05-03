#ifndef _Tree_
#define _Tree_

// Binary tree node abstract class
template <typename E> class BinNode {
    public:
    virtual ~BinNode() {} // Base destructor
    // Return the node’s value
    virtual E& element() = 0;
    // Set the node’s value
    virtual void setElement(const E&) = 0;
    // Return the node’s left child
    virtual BinNode* left() const = 0;
    // Set the node’s left child
    virtual void setLeft(BinNode*) = 0;
    // Return the node’s right child
    virtual BinNode* right() const = 0;
    // Set the node’s right child
    virtual void setRight(BinNode*) = 0;
    // Return true if the node is a leaf, false otherwise
    virtual bool isLeaf() = 0;
};

template <typename E> class BNode{
    private:
        E val;
        BNode *lc;
        BNode *rc;
    public:
        BNode(const E& val, BNode *left, BNode *right) : val(val), lc(left), rc(right) {};
        BNode(const E& val) : val(val), lc(nullptr), rc(nullptr) {};
        E& element() {
            return val;
        }
        void setElement(const E& it) {
            val = it;
        }
        BNode *left() const{
            return lc;
        }
        BNode *right() const {
            return rc;
        }
        void setLeft(BNode *left) {
            lc = left;
        }
        void setRight(BNode *right) {
            rc = right;
        }
        bool isLeaf() {
            if (!this->lc && !this->rc) return true; 
            return false;
        }
        ~BNode() {};
};

#endif