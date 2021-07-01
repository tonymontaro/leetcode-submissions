// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter

#define ll long long

class Solution {
public:
    int countLetters(string s) {
        char prev = s[0];
        int idx = 1;
        int left = 0;
        ll ans = 0;
        while (idx <= s.size()) {
            if (idx == s.size() || s[idx] != prev) {
                int n = idx - left;
                ans += (n * (1 + n)) / 2;
                left = idx;
            }
            if (idx < s.size()) prev = s[idx];
            idx++;
        }
        return ans;
    }
};
