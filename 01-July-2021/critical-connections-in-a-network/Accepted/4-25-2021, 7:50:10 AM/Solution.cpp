// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    int topo = 0;
    map<int, int> tmap;
    vector<vector<int>> res;
    int seen[100001];
    int explored[100001];
    map<int, vector<int>> adj;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        memset(seen, 0, sizeof(seen));
        memset(explored, 0, sizeof(explored));
        for (auto x: connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        solve(0, -1);
        return res;
    }
    int solve(int node, int parent) {
        if (seen[node] == 1) return tmap[node];
        seen[node] = 1;
        int currentTopo = topo++;
        tmap[node] = currentTopo;
        int best = INT_MAX;
        for (int child: adj[node]) {
            if (child == parent || explored[child] == 1) continue;

            int rs = solve(child, node);
            best = min(best, rs);
            if (rs > currentTopo) {
                // cout << node << " " << rs << " " << currentTopo << endl;
                res.push_back({min(node, child), max(node, child)});
            }
        }
        explored[node] = 1;
        // cout << node << " " << best << endl;
        return best;
    }
};