// https://leetcode.com/problems/distinct-subsequences-ii

class Solution {
    public int distinctSubseqII(String seq) {
        int n = seq.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;
        int[] lastSeen = new int[26];

        for (int i = 1; i < n + 1; i++) {
            char ch = seq.charAt(i - 1);
            int lastIdx = lastSeen[ch - 'a'];
            int toRemove = lastIdx == 0 ? 0 : dp[lastIdx - 1];
            dp[i] = dp[i - 1] * 2 - toRemove;
            lastSeen[ch - 'a'] = i;
        }

        return dp[n] - 1;
    }
}