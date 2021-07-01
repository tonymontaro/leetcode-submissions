// https://leetcode.com/problems/swim-in-rising-water

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pii, v<pii>, greater<>> pq;
        int seen[51][51];
        memset(seen, 0, sizeof(seen));
        seen[0][0] = 1;
        pq.push({grid[0][0], {0, 0}});
        vector<pi> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            int h = node.first, row = node.second.first, col = node.second.second;
            if (row == n-1 && col == n-1) return h;
            for (auto [rAdd, cAdd]: dirs) {
                int r = row + rAdd, c = col + cAdd;
                if (r < 0 || r >= n || c < 0 || c >= n || seen[r][c]) continue;
                seen[r][c] = 1;
                pq.push({max(grid[r][c], h), {r, c}});
            }
        }
        return 0;
    }
};