// https://leetcode.com/problems/binary-tree-level-order-traversal

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* node, int depth=0) {
        if (!node) return ans;
        
        if (depth >= ans.size()) {
            vector<int> vec;
            ans.emplace_back(vec);
        }
        ans[depth].emplace_back(node->val);
        levelOrder(node->left, depth + 1);
        levelOrder(node->right, depth + 1);
        return ans;
    }
};
 