// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

class Solution {
public:
    vector<int> arr;
    TreeNode* sortedListToBST(ListNode* head) {
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        
        return solve(0, arr.size() - 1);
    }
    TreeNode* solve(int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r + 1) / 2;
        auto* p = new TreeNode(arr[mid]);
        p->left = solve(l, mid - 1);
        p->right = solve(mid + 1, r);
        return p;
    }
};