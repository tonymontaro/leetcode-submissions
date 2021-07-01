// https://leetcode.com/problems/binary-tree-paths

class Solution {
public:
    vector<string> result;
    vector<int> st;
    vector<string> binaryTreePaths(TreeNode* root, string s = "") {
        if (!root->right && !root->left) {
            s += to_string(root->val);
            result.push_back(s);
            return result;
        }
        string ss = s + to_string(root->val) + "->";
        if (root->left) binaryTreePaths(root->left, ss);
        if (root->right) binaryTreePaths(root->right, ss);
        return result;
    }
};