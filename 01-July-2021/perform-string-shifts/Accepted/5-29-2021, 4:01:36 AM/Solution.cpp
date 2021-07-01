// https://leetcode.com/problems/perform-string-shifts

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sf = 0;
        for (auto row: shift) {
            if (row[0] == 1) sf += row[1];
            else sf -= row[1];
        }
        string ans(s.size(), '.');
        int n = s.size();
        sf = sf % n;
        for (int i = 0; i < n; i++) {
            int idx = (i + sf + n) % n;
            ans[idx] = s[i];
        }
        return ans;
    }
};