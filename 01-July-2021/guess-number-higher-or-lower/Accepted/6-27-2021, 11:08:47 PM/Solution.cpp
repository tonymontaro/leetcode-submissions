// https://leetcode.com/problems/guess-number-higher-or-lower

#define ll long long
class Solution {
public:
    int guessNumber(int n) {
        ll hi = n;
        ll lo = 1;
        while (lo <= hi) {
            ll mid  = lo + (hi - lo)/2;
            int rs = guess(mid);
            if (rs == 0) return mid;
            if (rs == 1) lo = mid + 1;
            else hi = mid - 1;
        }
        return 0;
    }
};