// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

#define v vector


class Solution {
public:
    int target;
    int bunch;
    int minDays(vector<int>& bloom, int m, int k) {
        if (m * k > bloom.size()) return -1;
        target = m; bunch = k;
        int lo = *min_element(bloom.begin(), bloom.end());
        int hi = *max_element(bloom.begin(), bloom.end());
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isValid(bloom, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    bool isValid(v<int> &bloom, int mid) {
        int cnt = 0;
        int done = 0;
        for (auto x: bloom) {
            if (x > mid) cnt = 0;
            else cnt++;
            if (cnt == bunch) {
                done++;
                cnt = 0;
            }
        }
        return done >= target;
    }
};