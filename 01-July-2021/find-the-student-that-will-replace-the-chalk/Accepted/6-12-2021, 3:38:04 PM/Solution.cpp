// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

#define ll long long


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll total = 0;
        for (auto x: chalk) total += x;
        total = k % total;
        for (int i = 0; i < chalk.size(); i++) {
            if (total < chalk[i]) return i;
            total -= chalk[i];
        }
        return 0;
    }
};