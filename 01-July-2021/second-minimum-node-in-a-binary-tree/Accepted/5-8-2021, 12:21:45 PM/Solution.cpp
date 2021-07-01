// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

class Solution {
public:
    set<int> vals;
    int findSecondMinimumValue(TreeNode* root) {
        solve(root);
        vector<int> v(vals.begin(), vals.end());
        return vals.size() == 1 ? -1 : v[1];
    }
    void solve(TreeNode* node) {
        if (!node) return;
        vals.insert(node->val);
        solve(node->right);
        solve(node->left);
    }
};