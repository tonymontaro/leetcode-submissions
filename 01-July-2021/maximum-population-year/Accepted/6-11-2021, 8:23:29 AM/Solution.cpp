// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int yearCount[3000] = {0};
        for (auto& x: logs) {
            for (int i = x[0]; i < x[1]; i++) yearCount[i]++;
        }
        int ans = 1950;
        for (int i = 1950; i < 2051; i++) if (yearCount[i] > yearCount[ans]) ans = i;
        return ans;
    }
};