// https://leetcode.com/problems/replace-all-digits-with-characters

class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); i += 2) {
            int shift = s[i + 1] - '0';
            char c = s[i] + shift;
            s[i + 1] = c;
        }
        return s;
    }
};