int height(Node* root) {
    if(!root) return 0;
    if(root->pLeft == nullptr && root->pRight == nullptr) return 1;
    int l = height(root->pLeft);
    int r = height(root->pRight);
    return 1 + max(l,r);
}

int getHeight() {
    // TODO: return height of the binary tree.
    return height(this->root);
}
    
string preOrder() {
        return preOrder(root);
    }

    string inOrder() {
        return inOrder(root);
    }

    string postOrder() {
        return postOrder(root);
    }
    
string preOrder(Node* node) {
        if (!node) {
            return "";
        }
        stringstream ss;
        ss << node->value << " ";
        ss << preOrder(node->pLeft);
        ss << preOrder(node->pRight);
        return ss.str();
    }

    string inOrder(Node* node) {
        if (!node) {
            return "";
        }
        stringstream ss;
        ss << inOrder(node->pLeft);
        ss << node->value << " ";
        ss << inOrder(node->pRight);
        return ss.str();
    }

    string postOrder(Node* node) {
        if (!node) {
            return "";
        }
        stringstream ss;
        ss << postOrder(node->pLeft);
        ss << postOrder(node->pRight);
        ss  << node->value << " ";
        return ss.str();
    }
// STUDENT ANSWER END