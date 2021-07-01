// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        multiset<char> a(s1.begin(), s1.end());
        multiset<char> b(s2.begin(), s2.end());
        if (a != b) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff++;
        }
        return diff == 0 || diff == 2;
    }
};