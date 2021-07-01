// https://leetcode.com/problems/number-of-1-bits

public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {

        int ans = 0;
        while (n != 0) {
            ans = ans + (n & 1);
            n = n >>> 1;
        }
        return ans;
    }
}