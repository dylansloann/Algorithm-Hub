// Time: O(length of list), space: O(1)
ListNode* swapPairs(ListNode* head) {
            
    ListNode* tmp = head;
    while (tmp != nullptr && tmp->next != nullptr) {
        int currVal = tmp->val;
        tmp->val = tmp->next->val;
        tmp->next->val = currVal;

        tmp = tmp->next->next;
    }

    
    return head;
}