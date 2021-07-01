// https://leetcode.com/problems/binary-tree-postorder-traversal

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
    void postOrder(TreeNode* node, vector<int>& arr) {
        if (!node) return;
        postOrder(node->left, arr);
        postOrder(node->right, arr);
        arr.push_back(node->val);
    }
};
