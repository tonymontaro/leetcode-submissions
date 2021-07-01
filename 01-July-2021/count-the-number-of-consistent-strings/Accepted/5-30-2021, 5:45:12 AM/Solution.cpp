// https://leetcode.com/problems/count-the-number-of-consistent-strings

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int alphas[26] = {0};
        for (auto c: allowed) alphas[c - 'a'] = 1;
        int ans = 0;
        for (auto &word: words) {
            int consistent = 1;
            for (auto c: word) if (alphas[c - 'a'] == 0) { 
                consistent = 0;
                    break;
            }
            ans += consistent;
        }
        return ans;
    }
};