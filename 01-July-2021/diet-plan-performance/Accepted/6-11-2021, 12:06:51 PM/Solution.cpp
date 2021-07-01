// https://leetcode.com/problems/diet-plan-performance

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sm = 0; int ans = 0;
        for (int i = 0; i < k; i++) sm += calories[i];
        ans += (sm < lower) ? -1 : ((sm > upper) ? 1 : 0);
        for (int i = k; i < calories.size(); i++) {
            sm -= calories[i - k];
            sm += calories[i];
            ans += (sm < lower) ? -1 : ((sm > upper) ? 1 : 0);
        } 
        return ans;
    }
};