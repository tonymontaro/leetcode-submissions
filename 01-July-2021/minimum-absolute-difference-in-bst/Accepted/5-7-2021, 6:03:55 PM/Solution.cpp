// https://leetcode.com/problems/minimum-absolute-difference-in-bst

class Solution {
public:
    int prev = -1000000;
    int ans = 1000000;
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return ans;
    }

    void helper(TreeNode *node){
        if (node->left) helper(node->left);
        ans = min(ans, node->val - prev);
        prev = node->val;
        if (node->right) helper(node->right);
    }
};