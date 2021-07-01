// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> locs;
        string vowels = "aeiouAEIOU";
        for (int i = 0; i < s.size(); i++) {
            int f = vowels.find(s[i]);
            if (f != -1) locs.push_back(i);
        }
        for (int i = 0; i < locs.size() / 2; i++) {
            swap(s[locs[i]], s[locs[locs.size() - i - 1]]);
        } 
        return s;
    }
};
