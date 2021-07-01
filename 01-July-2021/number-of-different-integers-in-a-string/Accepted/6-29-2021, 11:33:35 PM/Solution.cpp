// https://leetcode.com/problems/number-of-different-integers-in-a-string

class Solution {
public:
    int numDifferentIntegers(string word) {
        int i = 0, n = word.size();
        set<string> seen;
        while (i < n) {
            if (!isdigit(word[i])) {
                i++; continue;
            }
            string num = "";
            while (i < n && word[i] == '0') i++;
            while (i < n && isdigit(word[i])) {
                num += word[i];
                i++;
            }
            seen.insert(num);
        }
        return seen.size();
    }
};