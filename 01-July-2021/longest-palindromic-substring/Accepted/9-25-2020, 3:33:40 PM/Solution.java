// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
    public String longestPalindrome(String s) {
        // O(n^2) time
        if (s.length() <= 1) return s;
        String ans = s.substring(0, 1);
        int ln = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            int[] rs = check(i, i, s);
            int[] rs2 = check(i, i + 1, s);
            if (rs2[1] - rs2[0] > rs[1] - rs[0]) rs = rs2;
            if (rs[1] - rs[0] > ln) {
                ans = s.substring(rs[0], rs[1]);
                ln = rs[1] - rs[0];
            }
        }
        return ans;
    }

    int[] check(int l, int r, String s) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }
        return new int[]{l + 1, r};
    }
}