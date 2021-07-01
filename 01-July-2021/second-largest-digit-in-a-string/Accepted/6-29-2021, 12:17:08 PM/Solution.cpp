// https://leetcode.com/problems/second-largest-digit-in-a-string

#define v vector

class Solution {
public:
    int secondHighest(string s) {
        set<int> digits;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) digits.insert(s[i] - '0');
        } 
        if (digits.size() < 2) return -1;
        v<int> dig(digits.begin(), digits.end());
        return dig[dig.size() - 2];
    }
};