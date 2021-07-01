// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (auto c: text) cnt[c - 'a']++;
        string balloon = "balon";
        int ans = INT_MAX;
        for (auto c: balloon) {
            int rs = (c == 'l' || c == 'o') ? cnt[c-'a'] / 2 : cnt[c-'a'];
            ans = min(ans, rs); 
        }
        return ans;
    }
};