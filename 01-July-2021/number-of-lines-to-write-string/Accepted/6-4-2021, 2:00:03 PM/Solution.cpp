// https://leetcode.com/problems/number-of-lines-to-write-string

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int width = 0, lines = 1;
        for (char c: s) {
            int val = widths[c - 'a'];
            if (val + width > 100) {
                width = 0;
                lines++;
            }
            width += val;
        }
        return {lines, width};
    }
};