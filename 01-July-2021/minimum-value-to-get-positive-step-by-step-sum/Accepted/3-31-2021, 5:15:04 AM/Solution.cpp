// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int best = 1;
        int sm = 0;
        for (auto num: nums) {
            sm += num;
            best = min(best, sm);
        }
        return max(1, best * -1 + 1);
    }
};