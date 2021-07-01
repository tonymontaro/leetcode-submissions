// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers


class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
    int helper(TreeNode* node, int val) {
        if (!node) return 0;
        val = ((val << 1) | node->val);
        if (!node->right && !node->left) return val;
        return helper(node->left, val) + helper(node->right, val);
    }
};
