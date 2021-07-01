// https://leetcode.com/problems/matchsticks-to-square

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class Solution {
public:
    ll part;
    int n;
    vector<int> nums;
    ll cache[40000] = {0};
    bool makesquare(vector<int>& matchsticks) {
        ll total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        part = total / 4;
        n = matchsticks.size();
        nums = matchsticks;
        return solve(0, 0);
    }
    bool solve(ll sm, int mask) {
        if (cache[mask]) return false;
        ll total = 0;
        for (int i = 0; i < n; i++) if (((1 << i) & mask) == 0) total += nums[i];
        if (total == part) return true;

        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) != 0) continue;
            int m = mask | (1 << i);
            ll ss = sm + nums[i];
            if (ss > part) continue;
            if (ss == part) ss = 0;
            if (solve(ss, m)) return true;
        }
        
        cache[mask] = 1;
        return false;
    }
};