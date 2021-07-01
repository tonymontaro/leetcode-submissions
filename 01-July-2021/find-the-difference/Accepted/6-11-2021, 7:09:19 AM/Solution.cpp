// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int seen[26] = {0};
        for (auto x: t) seen[x - 'a']++;
        for (auto x: s) seen[x - 'a']--;
        for (int i = 0; i < 26; i++) if (seen[i]) return i + 'a';
        return 'a';
    }
};