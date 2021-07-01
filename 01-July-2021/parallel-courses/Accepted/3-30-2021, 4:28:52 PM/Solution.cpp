// https://leetcode.com/problems/parallel-courses

#define v vector


class Solution {
public:
    int topo = 1;
    map<int, int> tp;
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        v<v<int>> adj(n + 1);
        for (auto x: relations)
            adj[x[1]].push_back(x[0]);
        for (int i = 1; i < n + 1; i++)
            setTopo(i, adj);
        for (auto x: relations) {
            int a = x[0], b = x[1];
            if (tp[a] > tp[b]) return -1;
        }
        tp.clear();
        int res = 0;
        for (int i = 1; i < n + 1; i++)
            res = max(res, solve(i, adj));
        return res;
    }
    void setTopo(int node, v<v<int>> &adj) {
        if (tp.find(node) != tp.end()) return;
        tp[node] = 0;
        for (auto child: adj[node])
            setTopo(child, adj);
        tp[node] = topo++;
    }
    int solve(int node, v<v<int>> &adj) {
        if (tp.find(node) != tp.end()) return tp[node];
        int ans = 1;
        for (auto child: adj[node]) 
            ans = max(ans, 1 + solve(child, adj));
        tp[node] = ans;
        return ans;
    }
};