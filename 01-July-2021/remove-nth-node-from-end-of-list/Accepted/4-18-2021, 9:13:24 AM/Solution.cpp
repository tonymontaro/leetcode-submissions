// https://leetcode.com/problems/remove-nth-node-from-end-of-list

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *left = head;
        ListNode *right = head;
        for (int i = 0; i < n - 1; i++) right = right->next;
        ListNode *prev = nullptr;
        while (right->next) {
            prev = left;
            left = left->next;
            right = right->next;
        }
        if (!prev) return head->next;
        prev->next = left->next;
        return head;
    }
};