#include <iostream>

using std::cout, std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* returnList = new ListNode;
    ListNode* tmp = returnList;

    int val1 = 0;
    int val2 = 0;
    int sum = 0;
    bool carry = false;
    while (true) {
        val1 = 0;
        val2 = 0;

        if (l1 != nullptr) { val1 = l1->val;}
        if (l2 != nullptr) { val2 = l2->val;}

        sum = val1 + val2 + carry;
        if (sum > 9) { carry = true; }
        else { carry = false; }

        tmp->val = sum % 10;

        if (l1 != nullptr) { l1 = l1->next; }
        if (l2 != nullptr) { l2 = l2->next; }

        if (l1 == nullptr && l2 == nullptr && carry == false) { break; }

        tmp->next = new ListNode;
        tmp = tmp->next;
    }

    return returnList;
}