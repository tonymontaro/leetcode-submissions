// https://leetcode.com/problems/sqrtx

class Solution {
    public int mySqrt(int x) {
        if (x <= 0) return x;
        int lo = 1;
        int hi = 46340;
        int valid = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid * mid <= x) {
                valid = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return valid;
    }
}