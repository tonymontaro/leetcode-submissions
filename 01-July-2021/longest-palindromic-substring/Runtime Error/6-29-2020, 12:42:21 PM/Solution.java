// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
    static StringBuilder[][] dp;
    static char[] arr;
    public static String longestPalindrome(String s) {
        arr = s.toCharArray();
        dp = new StringBuilder[arr.length + 1][arr.length + 1];
        return solve(0, arr.length-1).toString();
    }

    static StringBuilder solve(int start, int end) {
        if (dp[start][end] == null) {
            StringBuilder res = new StringBuilder();
            if (start <= end) {
                StringBuilder skip = new StringBuilder();
                skip = solve(start + 1, end);
                StringBuilder include = new StringBuilder();
                include.append(arr[start]);
                int endIdx = start;
                for (int i = end; i > start; i--) if (arr[i] == arr[start]) endIdx = i;
                if (endIdx != start) {
                    include.append(solve(start + 1, endIdx - 1));
                    include.append(arr[endIdx]);
                }
                res = (include.length() > skip.length()) ? include : skip;
            }
            dp[start][end] = res;
        }
        return dp[start][end];
    }
}