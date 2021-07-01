// https://leetcode.com/problems/stone-game-vii

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector



class Solution {
public:
    pi* cache[1001][1001];
    int stoneGameVII(vector<int>& stones) {
        int sm = accumulate(stones.begin(), stones.end(), 0);
        auto res = solve(0, stones.size() - 1, sm, stones);
        return res->first - res->second;
    }
    pi* solve(int i, int j, int sm, vector<int>& stones) {
        if (cache[i][j] != nullptr) return cache[i][j];
        if (i == j) {
            cache[i][j] = new pair<ll, ll>(0, 0);
            return cache[i][j];
        }
        auto left = solve(i + 1, j, sm - stones[i], stones);
        auto right = solve(i, j - 1, sm - stones[j], stones);
        int l = sm - stones[i] + left->second;
        int r = sm - stones[j] + right->second;
        if (l - left->first > r - right->first) cache[i][j] = new pair<ll, ll>(l, left->first);
        else cache[i][j] = new pair<ll, ll>(r, right->first);
        return cache[i][j];
    }
};