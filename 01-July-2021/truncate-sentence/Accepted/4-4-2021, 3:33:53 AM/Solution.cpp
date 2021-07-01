// https://leetcode.com/problems/truncate-sentence

class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        int idx = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') cnt++;
            if (cnt == k){
                idx = i;
                break;
            }
        }
        return s.substr(0, idx);
    }
};
