// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
    public int bitwiseComplement(int n) {
        int num = n;
        int res = 1;
        n >>>= 1;
        while (n != 0) {
            res = (res << 1) + 1;
            n >>>= 1;
        }
        return res ^ num;
    }
}