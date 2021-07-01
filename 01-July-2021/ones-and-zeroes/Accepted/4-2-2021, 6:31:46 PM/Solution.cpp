// https://leetcode.com/problems/ones-and-zeroes

#define v vector

int cache[600][101][101];
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(cache, -1, sizeof(cache));
        return solve(0, m, n, strs);
    }
    int solve(int idx, int m, int n, v<string> &arr) {
        if ((n == 0 && m == 0) || idx >= arr.size()) return 0;
        if (cache[idx][m][n] != -1) return cache[idx][m][n];
        int ans = solve(idx + 1, m, n, arr);
        int zeros = 0;
        for (int i = 0; i < arr[idx].size(); i++)
            if (arr[idx][i] == '0')
                zeros++;
        int ones = arr[idx].size() - zeros;
        if (zeros <= m && ones <= n)
            ans = max(ans, 1 + solve(idx + 1, m - zeros, n - ones, arr));
        cache[idx][m][n] = ans;
        return ans;
    }
};