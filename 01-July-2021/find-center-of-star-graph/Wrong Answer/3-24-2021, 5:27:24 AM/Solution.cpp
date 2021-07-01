// https://leetcode.com/problems/find-center-of-star-graph

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        umap<int, int> cnt;
        for (auto x: edges) {
            cnt[x[0]]++;
            cnt[x[1]]++;
            if (cnt[x[0]] > 2) return x[0];
            if (cnt[x[1]] > 2) return x[1];
        }
        return 0;
    }
};