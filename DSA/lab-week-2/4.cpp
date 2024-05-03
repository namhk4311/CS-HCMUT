/*
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};
*/

ListNode* reverse(ListNode* head, int a, int b) {
    if (a==b) return head;
    
    a = a - 1;
    b = b - 1;
    
    ListNode* start = head;
    ListNode* end = head;
    while (a > 0) {
        start = start->right;
        end = end->right;
        a--;
        b--;
    }
    
    while (b>0) {
        end = end->right;
        b--;
    }
    
    //nailing the left of start and right of end
    ListNode* L = start->left;
    ListNode* R = end->right;
    
    //separating the reverse list
    start->left = NULL;
    end->right = NULL;
    
    //reversing the list
    ListNode* curr = start;
    ListNode* pre = start->left;
    ListNode* next = start->left;
    
    while (curr != NULL) {
        next = curr->right;
        curr->right = pre;
        if (pre) pre->left = curr;
        pre = curr;
        curr = next;
    }
    
    end->left = L;
    start->right = R;
    if (L) L->right = end;
    if (R) R->left = start;
    
    if (head==start) head = end;
    
    //delete
    return head;
}