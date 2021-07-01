// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) continue;
            int left = i - 1, right = i;
            char a = s[left], b = s[right];
            while (left >= 0 && right < s.size() && s[left--] == a && s[right++] == b)
                ans++;
        }
        return ans;
    }
};