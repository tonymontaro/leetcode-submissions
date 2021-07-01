// https://leetcode.com/problems/base-7

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        int sign = num < 0 ? -1 : 1;
        num = abs(num);
        string ans = "";
        while (num > 0) {
            ans += (num % 7) + '0';
            num = num / 7;
        }
        reverse(ans.begin(), ans.end());
        if (sign == -1) ans = "-" + ans;
        return ans;
    }
};