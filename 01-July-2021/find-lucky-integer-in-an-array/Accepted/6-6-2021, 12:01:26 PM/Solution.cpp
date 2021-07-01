// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> cnt(501, 0);
        int ans = -1;
        for (auto x: arr)cnt[x]++;
        for (auto x: arr) if (cnt[x] == x) ans = max(ans, x);
        return ans;
    }
};
