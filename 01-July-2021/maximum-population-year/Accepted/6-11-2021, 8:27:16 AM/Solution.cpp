// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int yearCount[3000] = {0};
        for (auto& x: logs) {
            yearCount[x[0]]++;
            yearCount[x[1]]--;
        }
        int ans[] = {0, 1949}; 
        int res = 0;
        for (int i = 1950; i < 2051; i++) {
            res += yearCount[i];
            if (res > ans[0]) { 
                ans[0] = res; ans[1] = i;
            }
        }
        return ans[1];
    }
};