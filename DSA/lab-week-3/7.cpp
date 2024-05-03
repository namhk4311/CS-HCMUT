// STUDENT ANSWER BEGIN
// You can define other functions here to help you.


void BFS()
{
    queue<Node *> q;
    //Node *tmp = root;
    q.push(root);
    while (!q.empty()) {
        Node *head = q.front();
        q.pop();
        cout << head->value << " ";
        if (head->pLeft) q.push(head->pLeft);
        if (head->pRight) q.push(head->pRight);
    }
}
// STUDENT ANSWER END