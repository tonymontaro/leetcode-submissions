// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        uset<int> seen;
        for (auto v: A) {
            if (seen.find(v) != seen.end()) return v;
            seen.insert(v);
        }
        return 0;
    }
};