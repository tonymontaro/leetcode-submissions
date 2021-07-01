// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
        int mn = 1e9, mx = 0;
        double total = 0;
        for (auto x: salary) {
            total += x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        total -= (mn + mx);
        return total / (salary.size() - 2);
    }
};
