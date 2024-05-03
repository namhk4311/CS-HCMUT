#include "main.h"
#include "Tree.h"
#include "BST.h"
using namespace std;
    

int main()
{
    int i = 0;
    BSTNode<int, int> *root = new BSTNode<int, int>(20, 0, new BSTNode<int, int>(15, 0), new BSTNode<int, int>(50, 0));
    cout << root->key() << " " << root->left()->key() << " " << root->right()->key() << endl; 
    
    return 0;
}