// https://leetcode.com/problems/valid-word-square

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        vector<string> cols(words.size());
        for (auto& w: words) {
            for (int c = 0; c < w.size(); c++) {
                cols[c] += w[c];
            }
        }
        for (int i = 0; i < words.size(); i++) {
            if (words[i] != cols[i]) return false;
        } 
        return true;
    }
};