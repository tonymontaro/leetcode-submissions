// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector



class Solution {
public:
    map<pair<int, ll>, ll> seen;
    int n;
    ll mod = 1e9 + 7;
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        return solve(0, 0, hats);
    }
    ll solve(int idx, ll mask, v<v<int>> &hats) {
        if (idx >= n) return 1;
        if (seen.find({idx, mask}) != seen.end())
            return seen[{idx, mask}];
        ll ans = 0;
        for (int hat: hats[idx]) {
            if ((mask & (1 << hat)) != 0) continue;
            int nmask = mask | (1 << hat);
            ans = (ans + solve(idx + 1, nmask, hats)) % mod;
        }
        
        seen[{idx, mask}] = ans;
        return ans;
    }
};