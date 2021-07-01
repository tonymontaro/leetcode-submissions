// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        int caps = 0, lows = 0;
        for (auto x: word) if (x == tolower(x)) lows++; else caps++;
        return caps == n || lows == n || (word[0] == toupper(word[0]) && lows == n - 1);
    }
};