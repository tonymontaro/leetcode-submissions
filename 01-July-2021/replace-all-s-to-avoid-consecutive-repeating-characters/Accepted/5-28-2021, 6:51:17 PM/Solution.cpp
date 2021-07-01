// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '?') continue;
            for (int j=0; j<26; ++j) {
                char c = j + 'a';
                if ((i > 0 && s[i-1] == c) || (i < s.size()-1 && s[i + 1] == c))
                    continue;
                s[i] = c;
                break;
            }
        }
        return s;
    }
};
