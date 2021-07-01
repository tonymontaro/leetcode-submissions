// https://leetcode.com/problems/palindrome-linked-list

string delim = " ";
#define print(x) cout << x << endl;
#define print2(x, y) cout << x << delim << y << endl;
#define print3(x, y, z) cout << x << delim << y << delim << z << endl;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while (node) {
            n++;
            node = node->next;
        }
        if (n == 1) return true;
        node = head;
        ListNode* prev = nullptr;
        for (int i = 1; i < n / 2; i++) {
            ListNode *tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        ListNode *other = node->next;
        node->next = prev;

        if (n % 2 == 1) other = other->next;
        while (node) {
            if (node->val != other->val) return false;
            node = node->next;
            other = other->next;
            
        }
        return true;
    }
};