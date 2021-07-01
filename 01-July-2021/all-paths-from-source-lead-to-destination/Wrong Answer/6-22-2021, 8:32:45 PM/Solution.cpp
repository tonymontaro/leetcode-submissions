// https://leetcode.com/problems/all-paths-from-source-lead-to-destination

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class Solution {
public:
    vector<vector<int>> edges2;
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        v<v<int>> mp(10001);
        v<int> topo(10001);
        int idx = 1;
        for (auto& x: edges) {
            mp[x[0]].push_back(x[1]);
        }
        if (!mp[destination].empty() || mp[source].empty()) return false;
        topological(source, mp, topo, idx);
        for (auto &x: edges2) {
            if (topo[x[0]] <= topo[x[1]]) return false;
        }
        return solve(source, mp, destination);
    }
    void topological(int node, v<v<int>> &mp, v<int>& topo, int& idx) {
        if (topo[node]) return;
        topo[node] = 1;
        for (auto& child: mp[node]) {
            edges2.push_back({node, child});
            topological(child, mp, topo, idx); 
        }
        topo[node] = idx++;
    }
    bool solve(int node, v<v<int>> &mp, int dest) {
        if (node == dest) return true;
        bool ans = !mp[node].empty();
        for (auto& child: mp[node]) ans = (ans && solve(child, mp, dest));
        return ans;
    }
};