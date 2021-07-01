// https://leetcode.com/problems/flip-game

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '-' || s[i-1] == '-') continue;
            string res = s.substr(0, i - 1);
            res += "--";
            res += s.substr(i + 1);
            ans.push_back(res);
        }
        return ans;
    }
};