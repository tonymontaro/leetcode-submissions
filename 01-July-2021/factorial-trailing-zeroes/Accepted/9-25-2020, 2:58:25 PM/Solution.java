// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
    public int trailingZeroes(int n) {
        int ans = 0;
        int mult = 5;
        while (mult <= n) {
            ans += (n / mult);
            mult *= 5;
        }
        return ans;
    }
}