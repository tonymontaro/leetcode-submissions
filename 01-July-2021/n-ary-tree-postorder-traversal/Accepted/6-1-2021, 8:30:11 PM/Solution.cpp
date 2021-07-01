// https://leetcode.com/problems/n-ary-tree-postorder-traversal

class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        helper(root);
        return ans;
    }
    void helper(Node* node) {
        if (!node) return;
        for (auto& child: node->children) helper(child);
        ans.push_back(node->val);
    }
};