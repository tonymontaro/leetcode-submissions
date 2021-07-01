// https://leetcode.com/problems/cousins-in-binary-tree

#define pi pair<int, int>
#define v vector

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) return false;
        map<int, pi> mp;
        deque<pair<TreeNode*, int>> st;
        st.push_back({root, 0});
        while(!st.empty()) {
            auto node = st.front();
            st.pop_front();
            if (node.first->right) {
                auto nd = node.first->right;
                if (nd->val == x || nd->val == y) mp[nd->val] = {node.first->val, node.second + 1};
                st.push_back({nd, node.second + 1});
            }
            if (node.first->left) {
                auto nd = node.first->left;
                if (nd->val == x || nd->val == y) mp[nd->val] = {node.first->val, node.second + 1};
                st.push_back({nd, node.second + 1});
            }
        }
        return (mp[x].first != mp[y].first) && (mp[x].second == mp[y].second);
    }
};