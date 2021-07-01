// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for(auto c: s) {
            if (c == ' ') {
                cnt = 0; continue;
            }
            cnt++;
        }
        return cnt;
    }
};