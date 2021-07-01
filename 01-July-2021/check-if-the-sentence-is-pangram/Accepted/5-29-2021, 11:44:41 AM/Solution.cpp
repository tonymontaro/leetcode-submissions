// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length() < 26) return false;
        int seen[26] = {0};
        for (auto c: sentence) seen[c - 'a'] = 1;
        for (int i = 0; i < 26; i++) if (seen[i] == 0) return false;
        return true;
    }
};