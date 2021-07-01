// https://leetcode.com/problems/missing-number-in-arithmetic-progression

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int best = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i-1];
            if (abs(diff) < abs(best)) best = diff;
        }
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i - 1] + best != arr[i]) return arr[i - 1] + best; 
        }
        return arr[0];
    }
};