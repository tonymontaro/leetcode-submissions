// https://leetcode.com/problems/flip-game

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '-' || s[i-1] == '-') continue;
            ans.push_back(s);
            ans.back()[i] = '-';
            ans.back()[i - 1] = '-';
        }
        return ans;
    }
};