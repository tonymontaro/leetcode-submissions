// https://leetcode.com/problems/find-the-distance-value-between-two-arrays

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (auto& x: arr1) {
            int valid = 1;
            for (auto& y: arr2) {
                if (abs(x - y) <= d) {
                    valid = 0;
                    break;
                }
            }
            ans += valid;
        }
        return ans;
    }
};