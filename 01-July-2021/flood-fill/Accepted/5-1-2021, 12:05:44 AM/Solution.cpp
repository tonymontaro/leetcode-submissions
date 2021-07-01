// https://leetcode.com/problems/flood-fill

class Solution {
public:
    int seen[50][50];
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int rlen = grid.size(), clen = grid[0].size();
        memset(seen, 0, sizeof(seen));
        int color = grid[sr][sc];
        if (color == newColor) return grid;
        stack<pair<int, int>> st;
        st.push({sr, sc});
        seen[sr][sc] = 1;
        grid[sr][sc] = newColor;
        vector<pair<int,int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            for (auto [rAdd, cAdd]: dirs) {
                int r = rAdd + node.first, c = cAdd + node.second;
                if (r < 0 || r >= rlen || c < 0 || c >= clen || seen[r][c] == 1 || grid[r][c] != color) continue;
                seen[r][c] = 1;
                st.push({r, c});
                grid[r][c] = newColor;
            }
        }
        return grid;
    }
};