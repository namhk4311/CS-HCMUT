// Function to merge two sorted linked lists
ListNode* mergeLists(ListNode* left, ListNode* right) {
    ListNode* result = nullptr;
    
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    
    if (left->val <= right->val) {
        result = left;
        result->next = mergeLists(left->next, right);
    } else {
        result = right;
        result->next = mergeLists(left, right->next);
    }
    
    return result;
}

// Function to split the linked list into two halves
void splitList(ListNode* source, ListNode** front, ListNode** back) {
    if (source == nullptr || source->next == nullptr) {
        *front = source;
        *back = nullptr;
        return;
    }

    ListNode* slow = source;
    ListNode* fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

// Merge sort for linked lists
ListNode* mergeSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Already sorted
    }

    ListNode* front;
    ListNode* back;
    splitList(head, &front, &back);

    front = mergeSortList(front);
    back = mergeSortList(back);

    return mergeLists(front, back);
}