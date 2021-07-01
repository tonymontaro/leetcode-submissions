// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros

class Solution {
public:
    bool checkZeroOnes(string s) {
        int ans[2] = {0, 0};
        char prev = '*'; int count = 0;
        for (auto c: s) {
            if (c != prev) {
                count = 0;
            }
            prev = c;
            count++;
            ans[c - '0'] = max(ans[c - '0'], count);
        }
        return ans[1] > ans[0];
    }
};