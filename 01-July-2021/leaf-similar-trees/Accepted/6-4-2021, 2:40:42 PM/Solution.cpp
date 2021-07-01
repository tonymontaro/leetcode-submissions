// https://leetcode.com/problems/leaf-similar-trees

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        setLeaves(root1, a);
        setLeaves(root2, b);
        return a == b;
    }
    void setLeaves(TreeNode* node, vector<int>& vec) {
        if (!node) return;
        if (!node->left && !node->right) vec.push_back(node->val);
        setLeaves(node->left, vec);
        setLeaves(node->right, vec);
    }
};