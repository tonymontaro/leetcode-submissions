// https://leetcode.com/problems/arranging-coins

#define ll long long

class Solution {
public:
    int arrangeCoins(int num) {
        ll lo = 1;
        ll hi = 80536;
        ll ans;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll pw = mid * (mid + 1) / 2;
            if (pw > num) hi = mid - 1;
            else {
                ans = mid;
                lo = mid + 1;
            }
        }

        return ans;
    }
};
