// https://leetcode.com/problems/number-of-1-bits

public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        char[] seq = Integer.toBinaryString(n).toCharArray();

        int ans = 0;
        for (char c: seq) if (c == '1') ans++;
        return ans;
    }
}