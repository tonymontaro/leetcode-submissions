// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* node = head;
        while(node) {
            for (int i = 0; i < m - 1; i++) {
                if (!node) break;
                node = node->next;
            }
            ListNode* remove = node;
            for (int i = 0; i < n + 1; i++) {
                if (!remove) break;
                remove = remove->next;
            } 
            if (node) node->next = remove;
            node = remove;
        }
        return head;
    }
};
