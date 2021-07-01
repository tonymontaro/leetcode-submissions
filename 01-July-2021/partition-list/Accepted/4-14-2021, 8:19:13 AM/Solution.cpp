// https://leetcode.com/problems/partition-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left, right;
        ListNode *leftNode = &left, *rightNode = &right;
        while (head) {
            auto next = head->next;
            if (head->val < x) {
                leftNode->next = head;
                leftNode = leftNode->next;
            } else {
                rightNode->next = head;
                rightNode = rightNode->next;
            }
            head->next = nullptr;
            head = next;
        }
        leftNode->next = right.next;
        return left.next;
    }
};