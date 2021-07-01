// https://leetcode.com/problems/inorder-successor-in-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    int target;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        target = p->val;
        solve(root);
        return ans;
    }
    void solve(TreeNode* node) {
        if (!node) return;
        if (node->val > target) {
            ans = node;
            solve(node->left);
        } else {
            solve(node->right);
        }
    }
};