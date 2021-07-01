// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time

class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int q) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) if (q >= s[i] && q <= e[i]) ans++;
        return ans;
    }
};