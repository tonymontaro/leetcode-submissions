// https://leetcode.com/problems/binary-tree-level-order-traversal

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* node) {
        solve(node, 0);
        return ans;
    }
    void solve(TreeNode* node, int depth) {
        if (!node) return;
        if (depth >= ans.size()) {
            ans.emplace_back(vector<int>());
        }
        ans[depth].emplace_back(node->val);
        solve(node->left, depth + 1);
        solve(node->right, depth + 1);
    }
};