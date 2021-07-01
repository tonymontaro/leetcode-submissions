// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int left = 0; int cost = 0;
        for (int i = 0; i < s.size(); i++) {
            cost += (s[i] == '(') ? 1 : -1;
            if (cost == 0) {
                ans += s.substr(left + 1, i - left - 1);
                left = i + 1;
            }
        }
        return ans;
    }
};