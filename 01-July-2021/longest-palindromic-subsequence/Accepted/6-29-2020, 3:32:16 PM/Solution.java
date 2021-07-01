// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
    static Integer[][] dp;
    static char[] arr;
    public static int longestPalindromeSubseq(String s) {
        if (s.equals("")) return 0;
        arr = s.toCharArray();
        dp = new Integer[arr.length + 1][arr.length + 1];
        return solve(0, arr.length-1);
    }

    static int solve(int start, int end) {
        if (dp[start][end] == null) {
            int res = 0;
            if (start <= end) {
                int skip = solve(start + 1, end);
                int include = 1;
                int endIdx = start;
                for (int i = end; i > start; i--) {
                    if (arr[i] == arr[start]) {
                        endIdx = i;
                        break;
                    }
                }
                if (endIdx > start) {
                    include += solve(start + 1, endIdx - 1) + 1;
                }
                res = Math.max(include, skip);
            }
            dp[start][end] = res;
        }
        return dp[start][end];
    }

}