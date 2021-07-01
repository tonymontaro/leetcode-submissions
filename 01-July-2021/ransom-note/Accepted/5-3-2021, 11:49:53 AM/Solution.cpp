// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ch[26];
        memset(ch, 0, sizeof(ch));
        for (char c: magazine) ch[c - 'a']++;
        for (char c: ransomNote) {
            int num = c - 'a';
            if (ch[num] == 0) return false;
            ch[num]--;
        }
        return true;
    }
};