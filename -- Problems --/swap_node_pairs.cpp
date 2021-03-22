struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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