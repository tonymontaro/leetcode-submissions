// https://leetcode.com/problems/n-ary-tree-preorder-traversal

class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* node) {
        if (!node) return res;
        res.push_back(node->val);
        for (auto child: node->children)
            preorder(child);
        return res;
    }
};