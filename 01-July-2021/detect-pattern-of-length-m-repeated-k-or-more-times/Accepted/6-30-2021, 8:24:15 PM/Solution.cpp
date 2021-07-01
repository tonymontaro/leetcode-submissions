// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int prod = m * k, n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i + m >= n) break;
            if (arr[i] == arr[i + m]) cnt++;
            else cnt = 0;
            if (cnt == (m * (k-1))) return true;
        }
        return false;
    }
};