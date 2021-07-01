// https://leetcode.com/problems/out-of-boundary-paths

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long


class Solution {
public:
    ll cache[52][52][52];
    int rlen, clen;
    v<pi> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    ll mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(cache, -1, sizeof(cache));
        rlen = m, clen = n;
        return solve(startRow, startColumn, maxMove);
    }
    int solve(int row, int col, int moves) {
        if (row < 0 || row >= rlen || col < 0 || col >= clen) return 1;
        if (moves == 0) return 0;
        if (cache[row][col][moves] != -1) return cache[row][col][moves];
        ll ans = 0;
        for (auto [rAdd, cAdd]: dirs) {
            ans = (ans + solve(row + rAdd, col + cAdd, moves - 1)) % mod;
        }
        cache[row][col][moves] = ans;
        return ans;
    }
};