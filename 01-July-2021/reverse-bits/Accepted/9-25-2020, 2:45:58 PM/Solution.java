// https://leetcode.com/problems/reverse-bits

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {

        int ans = 0;
        int count = 0;
        while (n != 0) {
            ans <<= 1;
            ans = ans | (n & 1);
            n = n >>> 1;
            count++;
        }
        for (int i = count; i < 32; i++) ans <<= 1;
        return ans;
    }
}