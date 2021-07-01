// https://leetcode.com/problems/valid-word-abbreviation

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() || j < abbr.size()) {
            if (i >= word.size() || j >= abbr.size()) return false;
            if (isalpha(abbr[j])) {
                if (abbr[j++] != word[i++]) return false;
                continue;
            }
            int num = abbr[j++] - '0';
            if (num == 0) return false;
            while (j < abbr.size() && isdigit(abbr[j])) num = num * 10 + (abbr[j++] - '0');
            i += num;
        }
        return i == word.size() && j == abbr.size();
    }
};