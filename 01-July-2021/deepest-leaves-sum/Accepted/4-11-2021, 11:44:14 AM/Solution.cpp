// https://leetcode.com/problems/deepest-leaves-sum

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        stack<pair<int, TreeNode*>> st;
        st.push({0, root});
        vector<pair<int, TreeNode*>> leaves;
        int mx = 0;
        while (!st.empty()) {
            auto a = st.top();
            auto node = a.second;
            int depth = a.first;
            st.pop();
            if (!node->left && !node->right) {
                mx = max(mx, depth);
                leaves.push_back(a);
            }
            if (node->right)
                st.push({depth + 1, node->right});
            if (node->left)
                st.push({depth + 1, node->left});
        }
        int ans = 0;
        for (auto [d, node]: leaves) if (d == mx) ans += node->val;
        return ans;
    }
};