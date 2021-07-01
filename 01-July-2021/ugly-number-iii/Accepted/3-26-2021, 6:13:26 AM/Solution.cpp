// https://leetcode.com/problems/ugly-number-iii

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector


class Solution {
public:
    int nthUglyNumber(int nn, int aa, int bb, int cc) {
        ll a = aa, b = bb, c = cc, n = nn;
        ll ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c);
        ll abc = lcm(ab, c);
        ll lo = 1;
        ll hi = 1e10;
        ll ans = 0;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll sm = mid / a;
            sm += mid / b;
            sm += mid / c;
            sm += mid / abc;
            sm -= mid / ab;
            sm -= mid / ac;
            sm -= mid / bc;
            if (sm >= n) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};