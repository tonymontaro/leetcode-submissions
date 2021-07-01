// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

class Solution {
public:
    TreeNode *ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
    int helper(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node || ans) return 0;
        int rs = 0;
        if (node == p || node == q) rs++;
        rs += helper(node->left, p, q) + helper(node->right, p, q);
        if (rs == 2 && !ans) ans = node;
        return rs;
    }
};