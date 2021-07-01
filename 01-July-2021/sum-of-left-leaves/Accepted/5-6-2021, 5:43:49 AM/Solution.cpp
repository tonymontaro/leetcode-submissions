// https://leetcode.com/problems/sum-of-left-leaves

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
    int sumOfLeftLeaves(TreeNode* root, char p = '*') {
        if (!root) return 0;
        if (!root->left && !root->right) 
            return (p == 'l') ? root->val : 0;
        return sumOfLeftLeaves(root->left, 'l') + sumOfLeftLeaves(root->right, 'r');
    }
};