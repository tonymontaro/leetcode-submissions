// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' || i == s.size() - 1) {
                if (i == s.size() - 1) i++;
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            }
        }
        return s;
    }
};