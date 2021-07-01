// https://leetcode.com/problems/minimum-distance-between-bst-nodes

#define v vector

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        v<int> vals;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            vals.push_back(node->val);
            if (node->left)
                st.push(node->left);
            if (node->right)
                st.push(node->right);
        }
        sort(vals.begin(), vals.end());
        int ans = vals[1] - vals[0];
        for (int i = 1; i < vals.size(); i++)
            ans = min(ans, vals[i] - vals[i - 1]);
        return ans;
    }
};
