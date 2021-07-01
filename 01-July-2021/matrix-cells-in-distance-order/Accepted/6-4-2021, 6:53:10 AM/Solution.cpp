// https://leetcode.com/problems/matrix-cells-in-distance-order

#define v vector

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> ans;
        ans.reserve(rows * cols);
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) ans.push_back({r, c});
        sort(ans.begin(), ans.end(), [rCenter, cCenter](v<int>& a, v<int>& b){
            int ad = abs(a[0] - rCenter) + abs(a[1] - cCenter);
            int bd = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            if (bd < ad) return false;
            return ad < bd;
        });
        return ans;
    }
};