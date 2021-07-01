// https://leetcode.com/problems/paint-house

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> prev = {0, 0, 0};
        for (int i = 0; i < costs.size(); i++) {
            int a = costs[i][0] + min(prev[1], prev[2]);
            int b = costs[i][1] + min(prev[0], prev[2]);
            int c = costs[i][2] + min(prev[0], prev[1]);
            prev = {a, b, c};
        }
        return min(prev[0], min(prev[1], prev[2]));
    }
};