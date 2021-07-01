// https://leetcode.com/problems/the-maze-ii

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rlen = maze.size(), clen = maze[0].size();
        v<v<int>> seen(rlen, v<int>(clen));
        priority_queue<pii, v<pii>, greater<>> pq;
        pq.push({0, {start[0], start[1]}});
        seen[start[0]][start[1]] = 1;
        v<pi> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dist = node.first, row = node.second.first, col = node.second.second;
            if (row == destination[0] && col == destination[1]) return dist;
            for (auto [rAdd, cAdd]: dirs) {
                int r = row + rAdd, c = col + cAdd;
                if (r < 0 || r >= rlen || c < 0 || c >= clen || maze[r][c] != 0) continue;
                while (r >= 0 && c >= 0 && r < rlen && c < clen && maze[r][c] == 0) {
                    r += rAdd; c += cAdd;
                }
                r -= rAdd; c -= cAdd;
                if (seen[r][c]) continue;
                seen[r][c] = 1;
                pq.push({dist + abs(row - r) + abs(col - c), {r, c}});
            }
        }
        return -1;
    }
};
