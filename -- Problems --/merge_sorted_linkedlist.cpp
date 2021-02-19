struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) { return l2; }
    if (l2 == nullptr) { return l1; }
    
    ListNode* returnList = new ListNode;
    ListNode* tmp = returnList;
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tmp->next = l1;
            l1 = l1->next;
        }
        else {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    
    if (l2 != nullptr) { tmp->next = l2; }
    else if (l1 != nullptr ) { tmp->next = l1; }
    
    // skips intial 0 node
    return returnList->next;
}