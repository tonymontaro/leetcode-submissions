// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> rs;
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) rs.push_back(1);
                else rs.push_back(ans.back()[j - 1] + ans.back()[j]);
            }
            ans.push_back(rs);
        }
        return ans;
    }
};