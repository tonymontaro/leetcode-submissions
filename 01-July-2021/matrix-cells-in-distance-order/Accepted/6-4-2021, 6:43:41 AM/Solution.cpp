// https://leetcode.com/problems/matrix-cells-in-distance-order

class Solution {
public:
    int seen[100][100];
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        memset(seen, 0, sizeof(seen));
        vector<vector<int>> ans;
        ans.reserve(rows * cols);
        deque<pair<int, int>> dq;
        dq.push_back({rCenter, cCenter});
        seen[rCenter][cCenter] = 1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!dq.empty()) {
            auto x = dq.front();
            dq.pop_front();
            ans.push_back({x.first, x.second});
            for (auto [rAdd, cAdd]: dirs) {
                int r = x.first + rAdd, c = x.second + cAdd;
                if (r < 0 || r >= rows || c < 0 || c >= cols || seen[r][c]) continue;
                seen[r][c] = 1;
                dq.push_back({r, c});
            }
        }
        return ans;
    }
};