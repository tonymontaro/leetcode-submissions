// https://leetcode.com/problems/construct-string-from-binary-tree

class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans;
        solve(root, ans);
        return ans;
    }
    void solve(TreeNode* node, string& s) {
        if (!node) return;
        s += to_string(node->val);
        if (!node->right && !node->left) return;
        s += "(";
        solve(node->left, s);
        s += ")";
        if (node->right) {
            s += "(";
            solve(node->right, s);
            s += ")";
        }
    }
};
