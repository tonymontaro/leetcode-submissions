// https://leetcode.com/problems/goal-parser-interpretation

class Solution {
public:
    string interpret(string s) {
        s = regex_replace(s, regex("\\(al\\)"), "al");
        s = regex_replace(s, regex("\\(\\)"), "o");
        return s;
    }
};