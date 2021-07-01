// https://leetcode.com/problems/closest-binary-search-tree-value

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root->left && target < root->val) {
            int rs = closestValue(root->left, target);
            return (abs(rs - target) < abs(root->val - target)) ? rs : root->val;
        }
        if (root->right && target > root->val) {
            int rs = closestValue(root->right, target);
            return (abs(rs - target) < abs(root->val - target)) ? rs : root->val;
        }
        return root->val;
    }
};