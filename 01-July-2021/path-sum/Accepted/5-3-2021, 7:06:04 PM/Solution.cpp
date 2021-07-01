// https://leetcode.com/problems/path-sum

class Solution {
public:
    int target;
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return helper(root, 0);
    }
    bool helper(TreeNode* root, int sm) {
        if (!root) return false;
        if (!root->left && !root->right) return sm + root->val == target;
        return helper(root->left, sm + root->val) || helper(root->right, sm + root->val);
    }
};