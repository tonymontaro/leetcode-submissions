// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal

#define v vector

class Solution {
public:
    bool invalid = false;
    int loc = 0;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
//        if (root->val != voyage[0]) return {-1};
        vector<int> ans;
        solve(root, voyage, ans);
        if (invalid) return {-1};
        return ans;
    }
    void solve(TreeNode* node, vector<int>& voyage, v<int> &ans){
        if (node->val != voyage[loc]) invalid = true;
        if (invalid) return;
        loc++;
        if (node->left && node->left->val != voyage[loc]) {
            swap(node->left, node->right);
            ans.push_back(node->val);
        }
        if (node->left) solve(node->left, voyage, ans);
        if (node->right) solve(node->right, voyage, ans);
    }

};