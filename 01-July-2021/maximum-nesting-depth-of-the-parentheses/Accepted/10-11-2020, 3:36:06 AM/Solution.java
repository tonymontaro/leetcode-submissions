// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
    public int maxDepth(String s) {
        int n = s.length();
        int mx = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                cur++;
                mx = Math.max(mx, cur);
            } else if (s.charAt(i) == ')')
                cur--;
        }

        return mx;
    }
}