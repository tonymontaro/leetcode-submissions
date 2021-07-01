// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

class Solution {
public:
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return ans;
    }
    vector<bool> solve(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node || ans != nullptr) return {false, false};
        auto left = solve(node->left, p, q);
        auto right = solve(node->right, p, q);
        vector<bool> rs = {left[0] || right[0], left[1] || right[1]};
        if (node == p) rs[0] = true;
        if (node == q) rs[1] = true;
        if (ans == nullptr && rs[0] && rs[1]) ans = node;
        return rs;
    }
};