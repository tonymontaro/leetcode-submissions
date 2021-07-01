// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        solve(root);
    }
    pair<TreeNode*, TreeNode*> solve(TreeNode* node) {
        if (!node->right && !node->left) return {node, node};
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        if (node->left) {
            auto l = solve(node->left);
            left = l.first;
            right = l.second;
        }
        if (node->right) {
            auto r = solve(node->right);
            if (!left) left = r.first;
            if (right) right->right = r.first;
            right = r.second;
        }
        node->left = nullptr;
        node->right = left;
        return {node, right};
    }
};