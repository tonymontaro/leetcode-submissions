// https://leetcode.com/problems/binary-tree-preorder-traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode* node, vector<int>& arr) {
        if (!node) return;
        arr.push_back(node->val);
        preorder(node->left, arr);
        preorder(node->right, arr);
    }
};
