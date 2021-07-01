// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        for (char x: s) {
            if (x == ' ') {
                reverse(word.begin(), word.end());
                ans += word + " ";
                word = "";
            } else {
                word += x;
            }
        }
        reverse(word.begin(), word.end());
        return ans + word;
    }
};