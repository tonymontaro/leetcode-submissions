// https://leetcode.com/problems/maximum-width-ramp

#define v vector

class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
        v<pair<int, int>> lows;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            if (lows.empty() || num < lows[lows.size()-1].first)
                lows.push_back({num, i});
            else
                ans = max(ans, i - binSearch(num, lows));
        } 
        return ans;
    }
    int binSearch(int num, v<pair<int, int>> &lows) {
        int lo = 0;
        int hi = lows.size() - 1;
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (lows[mid].first <= num) {
                ans = lows[mid].second;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};