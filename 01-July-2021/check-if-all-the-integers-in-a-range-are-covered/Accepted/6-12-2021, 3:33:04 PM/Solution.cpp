// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int i = left; i < right + 1; i++) {
            bool isCovered = false;
            for (auto& x: ranges) {
                if (x[0] <= i && i <= x[1]) isCovered = true;
            }
            if (!isCovered) return false;
        }

        return true;
    }
};