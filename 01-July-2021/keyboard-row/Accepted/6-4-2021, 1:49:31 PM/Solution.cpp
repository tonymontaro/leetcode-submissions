// https://leetcode.com/problems/keyboard-row

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int rank[26] = {0};
        vector<string> ans;
        string bb = "asdfghjkl", cc = "zxcvbnm";
        for (char x: bb) rank[x - 'a'] = 1;
        for (char x: cc) rank[x - 'a'] = 2;
        for (auto &word: words) {
            int r = rank[tolower(word[0]) - 'a'];
            bool valid = true;
            for (auto c: word) if (rank[tolower(c) - 'a'] != r) {
                valid = false;
                break;
            }
            if (valid) ans.push_back(word);
        }
        return ans;
    }
};