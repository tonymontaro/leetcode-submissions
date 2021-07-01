// https://leetcode.com/problems/find-all-the-lonely-nodes

class Solution {
public:
    vector<int> ans;
    vector<int> getLonelyNodes(TreeNode* root) {
        if (!root || !root->left && !root->right) return ans;
        if (root->left) {
            if (!root->right) ans.push_back(root->left->val);
            getLonelyNodes(root->left);
        }
        if (root->right) {
            if (!root->left) ans.push_back(root->right->val);
            getLonelyNodes(root->right);
        }
        return ans;
    }
};