// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int sz = high - low + 1;
        int ans = sz / 2;
        if (sz % 2 == 1 && high % 2 == 1) ans++;
        return ans;
    }
};
