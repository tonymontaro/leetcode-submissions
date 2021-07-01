// https://leetcode.com/problems/3sum-with-multiplicity

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        umap<int, ll> seen;
        ll ans = 0;
        ll mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int diff = target - (arr[i] + arr[j]);
                ans = (ans + seen[diff]) % mod;
            }
            seen[arr[i]] += 1;
        }
        return ans;
    }
};