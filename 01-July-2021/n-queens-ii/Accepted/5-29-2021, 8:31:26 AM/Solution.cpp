// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    int n;
    int col[10];
    int d1[25];
    int d2[25];
    int ans = 0;
    int totalNQueens(int nn) {
        n = nn;
        memset(col, 0, sizeof(col));
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        vector<string> vec;
        vec.reserve(n);
        for (int i = 0; i < n; i++) vec.emplace_back(n, '.');
        solve(0, vec);
        return ans;
    }
    void solve(int r, vector<string> &vec) {
        if (r >= n) {
            ans++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || d1[r + c] || d2[9 + r - c]) continue;
            col[c] = 1;
            d1[r + c] = 1;
            d2[9 + r - c] = 1;
            vec[r][c] = 'Q';
            solve(r + 1, vec);
            col[c] = 0;
            d1[r + c] = 0;
            d2[9 + r - c] = 0;
            vec[r][c] = '.';
        }
    }
};
