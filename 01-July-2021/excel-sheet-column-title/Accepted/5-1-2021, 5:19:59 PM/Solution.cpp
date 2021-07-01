// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int num) {
        string ans = "";
        while (num > 0) {
            int mod = num % 26;
            if (mod == 0) {
                ans += 'Z';
                num = (num / 26) - 1;
            } else {
                ans += ('A' + mod - 1);
                num = num / 26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};