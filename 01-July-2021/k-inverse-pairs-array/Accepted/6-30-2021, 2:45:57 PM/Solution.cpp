// https://leetcode.com/problems/k-inverse-pairs-array

#define ll long long

class Solution {
public:
    ll seen[1001][1001];
    ll mod = 1e9 + 7;
    int kInversePairs(int nn, int kk) {
        memset(seen, 0, sizeof(seen));
        for (int n = 1; n < nn + 1; n++) {
            ll total = (n * (n - 1)) / 2;
            seen[n][0] = 1;
            for (int k = 1; k < kk + 1; k++) {
                if (total < k) break;
                seen[n][k] = (seen[n - 1][k] + seen[n][k-1]) % mod;
                if (k >= n) seen[n][k] = (seen[n][k] - seen[n-1][k-n] + mod) % mod; 
            }
        }
        return seen[nn][kk];
    }
};