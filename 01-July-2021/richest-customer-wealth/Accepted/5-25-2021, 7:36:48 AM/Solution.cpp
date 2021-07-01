// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (int r = 0; r < accounts.size(); r++) {
            int res = 0;
            for (int c = 0; c < accounts[0].size(); c++) {
                res += accounts[r][c];
            }
            ans = max(ans, res);
        } 
        return ans;
    }
};
