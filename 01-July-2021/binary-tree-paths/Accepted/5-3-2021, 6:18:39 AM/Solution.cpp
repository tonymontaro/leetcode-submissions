// https://leetcode.com/problems/binary-tree-paths

class Solution {
public:
    vector<string> result;
    vector<int> st;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root->right && !root->left) {
            string s = "";
            for (auto x: st) s += (to_string(x) + "->");
            s += to_string(root->val);
            result.push_back(s);
            return result;
        }
        st.push_back(root->val);
        if (root->left) binaryTreePaths(root->left);
        if (root->right) binaryTreePaths(root->right);
        st.pop_back();
        return result;
    }
};