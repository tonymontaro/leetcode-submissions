// https://leetcode.com/problems/search-in-a-binary-search-tree

class Solution {
public:
    TreeNode* searchBST(TreeNode* node, int val) {
        while (node) {
            if (node->val == val) return node;
            else if (node->val > val) node = node->left;
            else node = node->right;
        }
        return nullptr;
    }
};