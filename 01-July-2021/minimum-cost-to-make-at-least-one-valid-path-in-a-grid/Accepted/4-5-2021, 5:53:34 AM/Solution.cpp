// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector

int seen[100][100];
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // (1 r) (2 l) (3 d) (4 u)
        int rlen = grid.size(), clen = grid[0].size();
        memset(seen, -1, sizeof(seen));
        priority_queue<pii, v<pii>, greater<>> pq;
        pq.push({0, {0, 0}});
        seen[0][0] = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dist = node.first, row = node.second.first, col = node.second.second;
            if (row == rlen-1 && col == clen - 1) return dist;
            if (row > 0) {
                int ct = (grid[row][col] == 4) ? 0 : 1;
                int ndist = dist + ct;
                int r = row - 1, c = col;
                if (seen[r][c] == -1 || ndist < seen[r][c]) {
                    seen[r][c] = ndist;
                    pq.push({ndist, {r, c}});
                }
            }
            if (row < rlen-1) {
                int ct = (grid[row][col] == 3) ? 0 : 1;
                int ndist = dist + ct;
                int r = row + 1, c = col;
                if (seen[r][c] == -1 || ndist < seen[r][c]) {
                    seen[r][c] = ndist;
                    pq.push({ndist, {r, c}});
                }
            }
            if (col > 0) {
                int ct = (grid[row][col] == 2) ? 0 : 1;
                int ndist = dist + ct;
                int r = row, c = col - 1;
                if (seen[r][c] == -1 || ndist < seen[r][c]) {
                    seen[r][c] = ndist;
                    pq.push({ndist, {r, c}});
                }
            }
            if (col < clen - 1) {
                int ct = (grid[row][col] == 1) ? 0 : 1;
                int ndist = dist + ct;
                int r = row, c = col + 1;
                if (seen[r][c] == -1 || ndist < seen[r][c]) {
                    seen[r][c] = ndist;
                    pq.push({ndist, {r, c}});
                }
            }
        }
        return -1;
    }
};