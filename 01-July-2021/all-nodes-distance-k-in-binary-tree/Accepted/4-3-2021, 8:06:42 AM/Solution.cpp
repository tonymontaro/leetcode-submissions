// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

#define v vector

int seen[501];
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, v<TreeNode*>> adj;
        stack <TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (node->left) {
            adj[node].push_back(node->left);
            adj[node->left].push_back(node);
            st.push(node->left);
            }
            if (node->right) {
            adj[node].push_back(node->right);
            adj[node->right].push_back(node);
            st.push(node->right);
            }
        }

        memset(seen, -1, sizeof(seen));
        deque<pair<TreeNode*, int>> deq;
        v<int> ans;
        deq.push_back({target, 0});
        seen[target->val] = 0;
        while (!deq.empty()) {
            auto node = deq.front();
            deq.pop_front();
            int dist = node.second;
            auto nd = node.first;
            if (dist == k) {
                ans.push_back(nd->val);
                continue;
            }
            for (auto child: adj[nd]) {
                if (seen[child->val] != -1) continue;
                seen[child->val] = dist + 1;
                deq.push_back({child, dist + 1});
            }
        }

        return ans;

    }
};
