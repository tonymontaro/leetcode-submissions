// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> count;
        int odd = 0;
        int ans = 0;
        for (auto x: s) count[x]++;
        for (auto [c, num]: count) {
            if (num % 2 == 1) {
                ans += num - 1;
                odd = 1;
            } else {
                ans += num;
            }
        }
        return ans + odd;
    }
};