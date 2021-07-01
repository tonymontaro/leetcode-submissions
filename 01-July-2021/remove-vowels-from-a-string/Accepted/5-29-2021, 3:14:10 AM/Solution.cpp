// https://leetcode.com/problems/remove-vowels-from-a-string

class Solution {
public:
    string removeVowels(string s) {
        string ans = "";
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (char c: s) {
            if (vowels.find(c) == vowels.end())
                ans += c;
        }
        return ans;
    }
};