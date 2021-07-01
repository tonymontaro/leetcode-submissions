// https://leetcode.com/problems/minimum-knight-moves

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector


class Solution {
public:
    int minKnightMoves(int x, int y) {
        v<pi> dirs = {{-2,1}, {-2,-1}, {2,1},{2,-1},
                      {-1, 2}, {-1,-2}, {1, 2}, {1,-2}};
        priority_queue<pii, v<pii>, greater<>> pq;
        x = abs(x);
        y = abs(y);
        pq.push({0, {x, y}});
        int seen[311][311];
        memset(seen, 0, sizeof(seen));
        seen[x][y] = 1;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dist = node.first;
            int row = node.second.first, col = node.second.second;
            if (row == 0 && col == 0) return dist;
            for (auto [rAdd, cAdd] : dirs) {
                int r = row + rAdd, c = col + cAdd;
                r = abs(r);
                c = abs(c);
                if (r > 309 || c > 309 || seen[r][c] == 1) continue;
                seen[r][c] = 1;
                pq.push({dist + 1, {r, c}});
            }
        }
        return 0;
    }
};