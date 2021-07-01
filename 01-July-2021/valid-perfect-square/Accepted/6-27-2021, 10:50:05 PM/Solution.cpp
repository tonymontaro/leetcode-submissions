// https://leetcode.com/problems/valid-perfect-square

#define ll long long


class Solution {
public:
    bool isPerfectSquare(int num) {
        ll lo = 1;
        ll hi = 65536;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll pw = mid * mid;
            if (pw == num) return true;
            if (pw > num) hi = mid - 1;
            else lo = mid + 1;
        }
        
        return false;
    }
};