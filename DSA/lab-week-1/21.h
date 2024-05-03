LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    stack<int> q;
    LLNode* res = NULL;
    int remember = 0;
    while (l0 != NULL && l1 != NULL) {
        int value = l0->val + l1->val + remember;
        if (value >= 10) remember = 1;
        else remember = 0;
        q.push(value % 10);
        l0 = l0->next;
        l1 = l1->next;
    }
    while (l0 != NULL) {
        int value = l0->val + remember;
        if (value >= 10) remember = 1;
        else remember = 0;
        q.push(value % 10);
        l0 = l0->next;
    }
    while (l1 != NULL) {
        int value = l1->val + remember;
        if (value >= 10) remember = 1;
        else remember = 0;
        q.push(value % 10);
        l1 = l1->next;
    }
    if (remember) {
        q.push(1);
    }
    while (q.size()) {
        if (res == NULL) {
            res = new LLNode(q.top(), NULL);
            q.pop();
        }
        else {
            res = new LLNode(q.top(), res);
            q.pop();
        }
    }
    return res;
}