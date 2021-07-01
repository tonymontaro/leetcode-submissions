// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3) return 0;
        int ans = 0;
        for (int i = 2; i < s.size(); i++) {
            char a = s[i], b = s[i - 1], c = s[i - 2];
            if (a != b && a != c && b != c) ans++;
        } 
        return ans;
    }
};
