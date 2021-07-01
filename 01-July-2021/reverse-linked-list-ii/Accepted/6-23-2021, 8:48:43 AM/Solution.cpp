// https://leetcode.com/problems/reverse-linked-list-ii

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = new ListNode();
        prev->next = head;
        head = prev;
        int idx = 1;
        ListNode* node = head;
        while (idx < left) {
            prev = prev->next;
            node = node->next;
            idx++;
        }
        ListNode *pv = node;
        node = node->next;
        while (idx <= right) {
            ListNode *nxt = node->next;
            node->next = pv;
            pv = node;
            node = nxt;
            idx++;
        }
        prev->next->next = node;
        prev->next = pv;
        return head->next;
    }
};