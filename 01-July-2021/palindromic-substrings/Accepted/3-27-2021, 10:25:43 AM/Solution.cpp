// https://leetcode.com/problems/palindromic-substrings

#define ll long long

class Solution {
public:
    int countSubstrings(string s) {
        ll ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += count(s, i, i);
            ans += count(s, i-1, i);
        } 
        return ans;
    }
    int count(string &s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) break;
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
};