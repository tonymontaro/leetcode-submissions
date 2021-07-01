// https://leetcode.com/problems/finding-the-users-active-minutes

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        
        map<int, set<int>> mp;
        for (auto x: logs) {
            mp[x[0]].insert(x[1]);
        }
        for (auto x: mp) {
            int cnt = x.second.size();
            ans[cnt - 1]++;
        }
        return ans;
    }
};