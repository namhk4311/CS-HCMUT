const int MOD = 27022001;

int sumDigitPath(BTNode* root) {
    if (root == nullptr) {
        return 0;
    }

    long long result = 0; 
    std::stack<std::pair<BTNode*, long long>> nodeStack;
    nodeStack.push(std::make_pair(root, root->val));

    while (!nodeStack.empty()) {
        BTNode* node = nodeStack.top().first;
        long long currentNumber = nodeStack.top().second;
        nodeStack.pop();

        if (node->left == nullptr && node->right == nullptr) {
            result = (result + currentNumber) % MOD;
        }

        if (node->left != nullptr) {
            nodeStack.push(std::make_pair(node->left, (currentNumber * 10 + node->left->val) % MOD));
        }
        if (node->right != nullptr) {
            nodeStack.push(std::make_pair(node->right, (currentNumber * 10 + node->right->val) % MOD));
        }
    }

    return static_cast<int>(result);
}